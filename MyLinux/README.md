# MyLinux

### Install preempt_rt patch for linux kernel on Ubuntu
```bash
sudo apt install build-essential git libssl-dev libelf-dev flex bison dwarves
wget https://mirrors.edge.kernel.org/pub/linux/kernel/v5.x/patch-5.15.79.xz
wget https://mirrors.edge.kernel.org/pub/linux/kernel/projects/rt/5.15/patch-5.15.79-rt54.patch.xz
xz -cd linux-5.15.79.xz | tar xvf -
cd linux-5.15.79
xzcat ../patch-5.15.79-rt54.patch.xz | patch -p1
make menuconfig # select "Fully Preemptible Kernel" in preemption model
```
Then go to `.config` file and delete every `debian/*.pem` you see.
```
make -j $(nproc) deb-pkg
sudo dpkg -i ../*.deb
```
After reboot you should be able to see something like this:
```
# uname -a
Linux icefox99-virtual-machine 5.15.79-rt54 #1 SMP PREEMPT_RT Mon Dec 12 16:53:18 JST 2022 x86_64 x86_64 x86_64 GNU/Linux
```