rm -rf ex02
mkdir ex02
cd ex02
mkdir test0 test2

dd if=/dev/zero of=test1 bs=1 count=4
dd if=/dev/zero of=test3 bs=1 count=1
dd if=/dev/zero of=test4 bs=1 count=2

chmod 715 test0
chmod 714 test1
chmod 504 test2
chmod 404 test3
chmod 641 test4


touch -t 201706012047 test0
touch -t 201706012146 test1
touch -t 201706012245 test2
touch -t 201706012344 test3
touch -t 201706012343 test4
ln -s test0 test6
touch -ht 201706012220 test6

link test3 test5

ls -l

tar -cf exo2.tar *

mkdir exo2
tar -xvf exo2.tar -C exo2

cd exo2

ls -l