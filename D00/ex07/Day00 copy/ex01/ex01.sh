rm -r ex01
mkdir ex01
cd ex01
dd if=/dev/zero of=testDay00 bs=1 count=40
touch -t 201706012342 testDay00
chmod 455 testDay00
ls -l
tar -cf testDay00.tar testDay00
rm testDay00