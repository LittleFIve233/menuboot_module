# menuboot_module
这是一个受邀制作的Wii U自启动模块

默认release仅仅支持taikoWiiU3，请自行更改titleID并编译使用

此module为特殊人群打造，正常使用者不需要

- 请注意，现无法启动带有更新补丁的软件
# HowToUse
0.需要Aroma或者Tiramisu

1.将99_autoboot.rpx重命名为98_autoboot.rpx

2.将99_menuboot.rpx放到sdhc:/wiiu/environments/[ENVIRONMENT]/modules/setup文件夹中

*3.如果你是所谓的特殊人群，要避免回到WiiU Menu，则需要把menuboot.rpx重命名为men.rpx放入sdhc:/wiiu/environments/[ENVIRONMENT]文件夹中以替换默认的WiiU Menu*
# ToDo
- 当未发现Title时自动返回WiiU Menu而不是强制死机

- 启动带有更新补丁的软件

# HowTobuild
你需要：
- devkitPro
- wut

在安装好devkitPro后

请输入：pacman -Syu, Pacman -Sy wut

随后输入make
