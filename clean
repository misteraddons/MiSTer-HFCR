# Define current project and other variables
PROJECT=$(cat CURRENT_PROJECT)
CURRENTDIR=$(pwd)

# Compile C code
cd src/$PROJECT
make clean
cd $CURRENTDIR

# Clear verilator
rm -rf targets/verilator/obj_dir/*