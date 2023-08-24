#include <coreinit/thread.h>
#include <coreinit/debug.h>
#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <sysapp/title.h>
#include <sysapp/launch.h>

int main(int argc, char **argv) {
	WHBProcInit();
	
	if (WHBProcIsRunning()) {
		if (
			SYSCheckTitleExists(0x00050000101d3000) // 检查Id是否存在
		)
		{
			uint64_t titleId = 0x00050000101d3000; // 如果你想更改自启动游戏，请更改此条
			_SYSLaunchTitleWithStdArgsInNoSplash(titleId, nullptr);
		} else {
			OSFatal("Failed to launch the specified APP!\nPlease check if this software exists!\nPress the power button for 4 seconds to turn off the console.\n\nThis feature comes from Menuboot Module.\nMenuBoot Module Created by LittlFIve.\nLastest build Time: 2023/08/24");
            /*
			WHBLogConsoleDraw(); // 使用屏幕渲染颜色的方法告知无法找到Title
			OSSleepTicks(OSMillisecondsToTicks(5000)); // 等待秒数，单位为毫秒
			SYSLaunchMenu(); // 返回WiiU Menu
			*/
		}

		while(WHBProcIsRunning()) {}
	}

	return 0;
}