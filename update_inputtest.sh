# Set target folder for Input Test
TARGETDIR=../InputTest_MiSTer
TARGETPROJ=inputtest

# Write current project file
echo "inputtest" > $TARGETDIR/CURRENT_PROJECT

# Clean old resources, C and HDL
rm -r $TARGETDIR/src/*
rm -r $TARGETDIR/resources/*
rm -r $TARGETDIR/rtl/*
rm -r $TARGETDIR/sys/*

# Copy new resources, C and HDL
cp -r resources/$TARGETPROJ $TARGETDIR/resources/$TARGETPROJ/
cp -r src/$TARGETPROJ $TARGETDIR/src/$TARGETPROJ/
cp -r src/shared $TARGETDIR/src/shared/
cp -r rtl/* $TARGETDIR/rtl/
cp -r sys/* $TARGETDIR/sys/
cp -r verilator/sim_main.cpp $TARGETDIR/verilator/
cp -r verilator/sim/* $TARGETDIR/verilator/sim/

# Remove resource working folders
rm -r $TARGETDIR/resources/$TARGETPROJ/sprites/res/
rm -r $TARGETDIR/resources/$TARGETPROJ/tilemap/res/
rm -r $TARGETDIR/resources/$TARGETPROJ/sound/res/
rm -r $TARGETDIR/resources/$TARGETPROJ/music/res/

# Clear build data
rm -r $TARGETDIR/src/$TARGETPROJ/build
rm -r $TARGETDIR/src/$TARGETPROJ/bin
mkdir $TARGETDIR/src/$TARGETPROJ/build
mkdir $TARGETDIR/src/$TARGETPROJ/bin