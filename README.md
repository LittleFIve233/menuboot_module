# menuboot_module
这是一个受邀制作的Wii U自启动模块

99_menuboot.rpx模块被放在sdhc:/wiiu/environments/[ENVIRONMENT]/module/setup/
99_autoboot.rpx重命名为98_autoboot.rpx

默认release仅仅支持taiko WiiU123，请自行更改titleID并编译使用

此module为特殊人群打造，正常使用者不需要
# HowTobuild
你需要：
- devkitPro
- wut

在安装好devkitPro后
请输入：pacman -Syu, Pacman -Sy wut
随后输入make
