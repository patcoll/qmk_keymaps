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

.PHONY: projectcain-firmware
projectcain-firmware: working_area/projectcain-firmware/relic/readme.md
working_area/projectcain-firmware/relic/readme.md:
	git clone https://github.com/projectcain/Board-Firmware working_area/projectcain-firmware

.PHONY: fruitbar-firmware
fruitbar-firmware: working_area/fruitbar-firmware/firmware/qmk/fruitbar/readme.md
working_area/fruitbar-firmware/firmware/qmk/fruitbar/readme.md:
	git clone https://github.com/blewis308/Fruitbar working_area/fruitbar-firmware

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

.PHONY: relic-default
relic-default: qmk_firmware/keyboards/relic/keymaps/default/keymap.c
qmk_firmware/keyboards/relic/keymaps/default/keymap.c: | qmk projectcain-firmware
	mkdir -p qmk_firmware/keyboards/relic
	rsync -avz working_area/projectcain-firmware/relic/ qmk_firmware/keyboards/relic/

.PHONY: fruitbar-default
fruitbar-default: qmk_firmware/keyboards/fruitbar/keymaps/default/keymap.c
qmk_firmware/keyboards/fruitbar/keymaps/default/keymap.c: | qmk fruitbar-firmware
	mkdir -p qmk_firmware/keyboards/fruitbar
	rsync -avz working_area/fruitbar-firmware/firmware/qmk/fruitbar/ qmk_firmware/keyboards/fruitbar/

.PHONY: caravan2
caravan2: | qmk
	mkdir -p qmk_firmware/keyboards/caravan2
	rsync -avz caravan2/ qmk_firmware/keyboards/caravan2/

.PHONY: agony
agony: | qmk
	mkdir -p qmk_firmware/keyboards/handwired/patcoll/agony
	rsync -avz handwired/patcoll/agony/ qmk_firmware/keyboards/handwired/patcoll/agony/

.PHONY: keymaps
keymaps: | qmk twoyo-default plop-default kawaii-default relic-default fruitbar-default caravan2 agony userspace
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
