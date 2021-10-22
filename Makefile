default: | keymaps qmk-clean

.PHONY: qmk
qmk: qmk_firmware/Makefile
qmk_firmware/Makefile:
	init-qmk

.PHONY: qmk-clean
qmk-clean:
	cd qmk_firmware && make git-submodule
	qmk clean -a

.PHONY: rainkeebs-resources
rainkeebs-resources: working_area/rainkeebs-resources/firmware
working_area/rainkeebs-resources/firmware:
	git clone https://github.com/rainkeebs/rainkeebs-resources working_area/rainkeebs-resources

.PHONY: rain-vial-qmk
rain-vial-qmk: working_area/vial-qmk/Makefile
working_area/vial-qmk/Makefile:
	git clone https://github.com/rainkeebs/vial-qmk working_area/vial-qmk

.PHONY: yohewi-qmk
yohewi-qmk: working_area/yohewi-qmk/Makefile
working_area/yohewi-qmk/Makefile:
	git clone https://github.com/yohewi/qmk_firmware working_area/yohewi-qmk

.PHONY: twoyo-default
plop-default: qmk_firmware/keyboards/twoyo/keymaps/default/keymap.c
qmk_firmware/keyboards/twoyo/keymaps/default/keymap.c: | qmk rainkeebs-resources
	mkdir -p qmk_firmware/keyboards/twoyo
	rsync -avz working_area/rainkeebs-resources/firmware/twoyo/ qmk_firmware/keyboards/twoyo/

.PHONY: plop-default
plop-default: qmk_firmware/keyboards/plop/keymaps/default/keymap.c
qmk_firmware/keyboards/plop/keymaps/default/keymap.c: | qmk rain-vial-qmk
	mkdir -p qmk_firmware/keyboards/plop
	rsync -avz working_area/vial-qmk/keyboards/plop/ qmk_firmware/keyboards/plop/

.PHONY: kawaii-default
kawaii-default: qmk_firmware/keyboards/kawaii/keymaps/default/keymap.c
qmk_firmware/keyboards/kawaii/keymaps/default/keymap.c: | qmk yohewi-qmk
	mkdir -p qmk_firmware/keyboards/kawaii
	rsync -avz working_area/yohewi-qmk/keyboards/kawaii/ qmk_firmware/keyboards/kawaii/

.PHONY: keymaps
keymaps: qmk_firmware/keyboards/plop/keymaps/patcoll/keymap.c
qmk_firmware/keyboards/plop/keymaps/patcoll/keymap.c: | qmk twoyo-default plop-default kawaii-default userspace
	init-keymaps

.PHONY: userspace
userspace: qmk_firmware/users/patcoll/patcoll.h
qmk_firmware/users/patcoll/patcoll.h: qmk
	init-userspace

.PHONY: test
test: | default
	build-all-keymaps

.PHONY: clean
clean:
	rm -rf qmk_firmware working_area
	mkdir -p working_area
