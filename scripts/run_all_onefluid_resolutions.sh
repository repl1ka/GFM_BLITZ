# Compile code
cd ..
make
cd ./scripts

# Exit if any simulations fail
set -e

# First set up the settings file (leave RS_pure, FS, CFL, IC, BCs unchanged)
sed -i 's/numGC.*/numGC 2/g' ./../settings_file.txt
sed -i 's/fluid1_gamma.*/fluid1_gamma 1.4/g' ./../settings_file.txt
sed -i 's/eos1.*/eos1 ideal/g' ./../settings_file.txt
sed -i 's/sim.*/sim onefluid/g' ./../settings_file.txt

allLs=( 10 20 40 80 160 320 640 1280 )

for j in "${allLs[@]}"
do
	sed -i "s/length.*/length ${j}/g" ./../settings_file.txt
	cd ..
	./1D_Euler_GFM.exe
	cd ./scripts
done
