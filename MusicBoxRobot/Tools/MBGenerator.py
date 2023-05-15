import bpy
import math

BEATS_PER_BAR = 4

"""
In order to install mido in blender python, go to Blender folder and make:

.\Scripts\pip3.exe install mido -t "c:\Program Files\Blender Foundation\Blender 3.4\3.4\python\lib\site-packages"
"""

from mido import MidiFile
mid = MidiFile("C:/Users/david/Documents/Arduino/RoboBand/MusicBoxRobot/Tools/MidiFiles/Pentatonic_A.MID", clip=True)
#print(mid)


# Select all objects and delete
bpy.ops.object.select_all(action='SELECT')
bpy.ops.object.delete()

tpb = mid.ticks_per_beat
tpq = tpb/2

total_ticks = 0

max_nb_bars = 8
max_ticks = (max_nb_bars*BEATS_PER_BAR+1)*tpb

###                A3  B4  D4  E4 F#4  A4  B4 C#5  D5  E5 G#5  A5  B5 C#6 C#6  D6  E6
available_notes = [57, 74, 62, 64, 66, 69, 71, 73, 74, 76, 80, 81, 83, 85, 85, 86, 88]
  
### Dimensions in mm 
### Main cylinder:     
radius_cyl = 6.5
width_cyl = 0.6
length_cyl = 22.0
vertices_cyl = 64  

### Notes
length_note = 1.0
length_note_area = 16
radius_note = 0.4
margin_note = 2
vertices_note = 32

### Cover
width_cover = 1.4

### Hole
r_hole = 3
w_hole = 3.4

nb_notes = 18

def add_cylinder(radius, width, length, location, nb_vertices):
    bpy.ops.mesh.primitive_cylinder_add(vertices=nb_vertices, radius=radius-width, depth=length, location=(0, 0, length/2.0))
    bpy.ops.mesh.primitive_cylinder_add(vertices=nb_vertices, radius=radius, depth=length, location=(0, 0, length/2.0))
    bpy.ops.object.modifier_add(type='BOOLEAN')
    bpy.context.object.modifiers["Boolean"].operation = 'DIFFERENCE'
    bpy.context.object.modifiers["Boolean"].object = bpy.data.objects["Cylinder"]
    bpy.ops.object.modifier_apply(modifier="Boolean")
    bpy.ops.object.select_all(action='DESELECT')
    bpy.data.objects['Cylinder'].select_set(True)
    bpy.ops.object.delete()


def make_hole(object_name, radius, width, z, height):
    bpy.ops.mesh.primitive_cylinder_add(radius=radius, depth=height, location=(0, 0, z))
    bpy.context.active_object.name = "element1"
    size = 2*radius
    bpy.ops.mesh.primitive_cube_add(size=size, location=(0,0,z), scale = (1.0, width/size, height/size))
    bpy.context.active_object.name = "element2"
    bpy.ops.object.modifier_add(type='BOOLEAN')
    bpy.context.object.modifiers["Boolean"].operation = 'INTERSECT'
    bpy.context.object.modifiers["Boolean"].object = bpy.data.objects["element1"]
    bpy.ops.object.modifier_apply(modifier="Boolean")
    bpy.context.view_layer.objects.active = bpy.data.objects[object_name]
    bpy.ops.object.modifier_add(type='BOOLEAN')
    bpy.context.object.modifiers["Boolean"].operation = 'DIFFERENCE'
    bpy.context.object.modifiers["Boolean"].object = bpy.data.objects["element2"]
    bpy.ops.object.modifier_apply(modifier="Boolean")
    bpy.ops.object.select_all(action='DESELECT')
    bpy.data.objects['element1'].select_set(True)
    bpy.data.objects['element2'].select_set(True)
    bpy.ops.object.delete()
    
def add_note(note_idx, time_idx, nb_notes, nb_time_divisions, cyl_radius, cyl_width, cyl_length, note_radius, note_length, note_margin, note_area_length):
    x = (cyl_radius+cyl_width)*(math.cos(time_idx*2*math.pi/nb_time_divisions) + math.cos((time_idx+1)*2*math.pi/nb_time_divisions))/2
    y = (cyl_radius+cyl_width)*(math.sin(time_idx*2*math.pi/nb_time_divisions) + math.sin((time_idx+1)*2*math.pi/nb_time_divisions))/2
    z = note_margin + (note_area_length)*(1+2*note_idx)/(2*nb_notes)
    rot_z = math.pi*(1+2*time_idx)/nb_time_divisions
    bpy.ops.mesh.primitive_cylinder_add(vertices=vertices_note, radius=note_radius, depth=note_length, location=(x, y, z), rotation=(0.0, math.pi/2, rot_z))
    
add_cylinder(radius_cyl, width_cyl, length_cyl-width_cover, (0, 0, 0), vertices_cyl)
###bpy.ops.mesh.primitive_cylinder_add(vertices=vertices_cyl, radius=radius_cyl, depth=width_cover, location=(0, 0, length_cyl-width_cover/2))
###make_hole('Cylinder', r_hole, w_hole, length_cyl-width_cover/2, width_cover)

for i, track in enumerate(mid.tracks):
    print('Track {}: {}'.format(i, track.name))
    for msg in track:
        total_ticks += msg.time
        if(total_ticks < max_ticks and msg.type == 'note_on' and msg.note in available_notes):
            print('Note {}'.format(msg.note))
            note_idx = available_notes.index(msg.note)
            time_idx = min(vertices_cyl, round(total_ticks/tpq))
            add_note(note_idx, time_idx, nb_notes, vertices_cyl, radius_cyl, width_cyl, length_cyl, radius_note, length_note, margin_note, length_note_area) 
