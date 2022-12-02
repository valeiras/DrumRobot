cat ./robot_config.h > tmp.h
sed '/#include/d' ./drum_robot.h >> tmp.h
sed '/#include/d' ./drum_song.h >> tmp.h
sed '/#include/d' ./drum_song_sheets.h >> tmp.h

cat tmp.h > tmp.cpp
sed '/#include/d' ./drum_robot.cpp >> tmp.cpp
sed '/#include/d' ./drum_song.cpp >> tmp.cpp
sed '/#include/d' ./drum_song_sheets.cpp >> tmp.cpp

cat tmp.cpp > all.ino
sed '/#include/d' ./DrumRobot.ino >> all.ino

echo '#include <Servo.h>' | cat - all.ino > temp && mv temp all.ino

rm ./tmp.h
rm ./tmp.cpp