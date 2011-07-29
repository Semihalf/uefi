EXTRA_PACKAGES=build-essential,swig,aptitude,debootstrap,libreadline5-dev

clean:
	- sudo umount -f debian_ppc_lenny/proc
	- sudo umount -f debian_ppc_lenny/sys
	- sudo umount -f debian_ppc_lenny/dev/shm
	- sudo umount -f debian_ppc_lenny/dev/pts
	- sudo umount -f debian_ppc_lenny/dev
	- sudo rm -rf debian_ppc_lenny

debian_ppc_lenny:
	mkdir -p $@/usr/bin/
	sudo cp /usr/bin/qemu-ppc-static $@/usr/bin/
	sudo debootstrap --include=$(EXTRA_PACKAGES) --arch powerpc lenny $@ http://apt-proxy:3142/debian/
	#sudo mount -t proc none debian_ppc_lenny/proc
	#sudo mount -t sysfs none debian_ppc_lenny/sys
	#sudo mount --rbind /dev debian_ppc_lenny/dev
	#sudo chroot debian_ppc_lenny uname -m

debian_ppc_lenny.tgz: debian_ppc_lenny
	sudo tar -zcf $@ debian_ppc_lenny
