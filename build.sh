# Define current project and other variables
PROJECT=$(cat CURRENT_PROJECT)
CURRENTDIR=$(pwd)

echo $PROJECT

# Compile C code
cd resources/$PROJECT/src
make clean
make all
cd $CURRENTDIR

# Compile verilator code
cd verilator
./verilate.sh
cd $CURRENTDIR

# Hexify roms
od -An -t x1 -v resources/$PROJECT/src/bin/os.bin > verilator/rom.hex
od -An -t x1 -v resources/$PROJECT/src/bin/os.bin > verilator/x64/Release/rom.hex
od -An -t x1 -v resources/$PROJECT/src/bin/os.bin > rtl/rom.hex
od -An -t x1 -v PETSCII.pf > verilator/font.hex
od -An -t x1 -v PETSCII.pf > verilator/x64/Release/font.hex
od -An -t x1 -v PETSCII.pf > rtl/font.hex
od -An -t x1 -v resources/sprite.bin > verilator/sprite.hex
od -An -t x1 -v resources/sprite.bin > rtl/sprite.hex
od -An -t x1 -v resources/sprite.bin > verilator/x64/Release/sprite.hex
od -An -t x1 -v resources/palette.bin > verilator/palette.hex
od -An -t x1 -v resources/palette.bin > rtl/palette.hex
od -An -t x1 -v resources/palette.bin > verilator/x64/Release/palette.hex
od -An -t x1 -v resources/music.bin > verilator/music.hex
od -An -t x1 -v resources/music.bin > rtl/music.hex
od -An -t x1 -v resources/music.bin > verilator/x64/Release/music.hex
od -An -t x1 -v resources/sound.bin > verilator/sound.hex
od -An -t x1 -v resources/sound.bin > verilator/x64/Release/sound.hex
od -An -t x1 -v resources/sound.bin > rtl/sound.hex
od -An -t x1 -v resources/tilemap.bin > verilator/tilemap.hex
od -An -t x1 -v resources/tilemap.bin > rtl/tilemap.hex
od -An -t x1 -v resources/tilemap.bin > verilator/x64/Release/tilemap.hex