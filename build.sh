# Define current project and other variables
PROJECT=$(cat CURRENT_PROJECT)
CURRENTDIR=$(pwd)

# Compile C code
cd src/$PROJECT
#make clean
make all
cd $CURRENTDIR

# Compile verilator code
cd verilator
./verilate.sh
cd $CURRENTDIR

# Hexify roms
od -An -t x1 -v src/$PROJECT/bin/os.bin > verilator/rom.hex
od -An -t x1 -v src/$PROJECT/bin/os.bin > verilator/x64/Release/rom.hex
od -An -t x1 -v src/$PROJECT/bin/os.bin > rtl/rom.hex
od -An -t x1 -v PETSCII.pf > verilator/font.hex
od -An -t x1 -v PETSCII.pf > verilator/x64/Release/font.hex
od -An -t x1 -v PETSCII.pf > rtl/font.hex
od -An -t x1 -v resources/$PROJECT/sprite.bin > verilator/sprite.hex
od -An -t x1 -v resources/$PROJECT/sprite.bin > rtl/sprite.hex
od -An -t x1 -v resources/$PROJECT/sprite.bin > verilator/x64/Release/sprite.hex
od -An -t x1 -v resources/$PROJECT/palette.bin > verilator/palette.hex
od -An -t x1 -v resources/$PROJECT/palette.bin > rtl/palette.hex
od -An -t x1 -v resources/$PROJECT/palette.bin > verilator/x64/Release/palette.hex
od -An -t x1 -v resources/$PROJECT/music.bin > verilator/music.hex
od -An -t x1 -v resources/$PROJECT/music.bin > rtl/music.hex
od -An -t x1 -v resources/$PROJECT/music.bin > verilator/x64/Release/music.hex
od -An -t x1 -v resources/$PROJECT/sound.bin > verilator/sound.hex
od -An -t x1 -v resources/$PROJECT/sound.bin > verilator/x64/Release/sound.hex
od -An -t x1 -v resources/$PROJECT/sound.bin > rtl/sound.hex
od -An -t x1 -v resources/$PROJECT/tilemap.bin > verilator/tilemap.hex
od -An -t x1 -v resources/$PROJECT/tilemap.bin > rtl/tilemap.hex
od -An -t x1 -v resources/$PROJECT/tilemap.bin > verilator/x64/Release/tilemap.hex