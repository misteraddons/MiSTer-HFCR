OPTIMIZE="-O3 --x-assign fast --x-initial fast --noassert"
#WARNINGS="-Wno-TIMESCALEMOD"
DEFINES="+define+SIMULATION=1 "
RTL="../../rtl"
readarray -t DEFINE_LINES < ../../src/$1/.define
for i in "${DEFINE_LINES[@]}"
do
	if ! [[ $i == //* ]]; then
		DEFINES+="+define+$i "
	fi
done
echo "verilator -cc --compiler msvc $DEFINES $WARNINGS $OPTIMIZE"
verilator -cc --compiler msvc $DEFINES $WARNINGS $OPTIMIZE \
--converge-limit 6000 \
--top-module emu sim.v \
-I$RTL \
-I$RTL/JTFRAME \
-I$RTL/jt49 \
-I$RTL/jt5205 \
-I$RTL/tv80
