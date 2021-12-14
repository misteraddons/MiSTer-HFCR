export OPTIMIZE="-O3 --x-assign fast --x-initial fast --noassert"
#export OPTIMIZE="-O0 --x-assign unique --x-initial unique --assert"
export WARNINGS="-Wno-TIMESCALEMOD"
#export WARNINGS="-Wno-TIMESCALEMOD -Wno-MULTIDRIVEN -Wpedantic"

set -e
if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null ; then
verilator \
-cc --compiler msvc +define+SIMULATION=1 $WARNINGS $OPTIMIZE \
--converge-limit 6000 \
--top-module emu sim.v \
-I../rtl \
-I../rtl/JTFRAME \
-I../rtl/jt49 \
-I../rtl/tv80
else
	echo "not running on windows"
fi
