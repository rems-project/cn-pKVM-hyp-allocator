# rm -rf build/
# mkdir build
cc -E -P -CC driver.c > driver.pp.c
cn instrument ./driver.pp.c --output=driver.pp.exec.c --output-dir=build/
echo "Compiling..."
cc -g -c -O0 -std=gnu11 -I$OPAM_SWITCH_PREFIX/lib/cn/runtime/include build/driver.pp.exec.c
echo "Linking..."
cc driver.pp.exec.o $OPAM_SWITCH_PREFIX/lib/cn/runtime/libcn_exec.a -L $OPAM_SWITCH_PREFIX/lib/cn/runtime -lcn_exec -o driver.exe
./driver.exe
echo "Done!"