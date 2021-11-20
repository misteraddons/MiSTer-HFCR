# Make C code
cd src
make clean
make all
cd ..

# Verilate HDL
cd verilator
./verilate.sh
cd ..

# Hexify roms
od -An -t x1 -v src/os.bin > verilator/rom.hex
od -An -t x1 -v src/os.bin > verilator/x64/Release/rom.hex
od -An -t x1 -v src/os.bin > rtl/rom.hex
od -An -t x1 -v PETSCII.pf > verilator/font.hex
od -An -t x1 -v PETSCII.pf > verilator/x64/Release/font.hex
od -An -t x1 -v PETSCII.pf > rtl/font.hex
od -An -t x1 -v gfx/sprite.bin > verilator/sprite.hex
od -An -t x1 -v gfx/sprite.bin > rtl/sprite.hex
od -An -t x1 -v  gfx/sprite.bin > verilator/x64/Release/sprite.hex
od -An -t x1 -v gfx/palette.bin > verilator/palette.hex
od -An -t x1 -v gfx/palette.bin > rtl/palette.hex
od -An -t x1 -v  gfx/palette.bin > verilator/x64/Release/palette.hex

od -An -t x1 -v  music/music.ym > verilator/music.hex
od -An -t x1 -v  music/music.ym > rtl/music.hex
od -An -t x1 -v  music/music.ym > verilator/x64/Release/music.hex