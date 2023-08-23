#include <coreinit/thread.h>
#include <coreinit/debug.h>
#include <coreinit/time.h>

#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>

#include <sysapp/title.h>
#include <sysapp/launch.h>

int main(int argc, char **argv) {
	WHBProcInit();
	WHBLogConsoleInit();
	
	if (WHBProcIsRunning()) {
		if (
			SYSCheckTitleExists(0x0005000010132200) // 检查Id是否存在
		)
		{
			uint64_t titleId = 0x0005000010132200;  // 如果你想更改自启动游戏，请更改此条
			_SYSLaunchTitleWithStdArgsInNoSplash(titleId, nullptr);
		} else {
			OSCalendarTime tm;
            OSTicksToCalendarTime(OSGetTime(), &tm);
			OSFatal("Failed to launch the specified APP!\nPlease check if this software exists!\nPress the power button for 4 seconds to turn off the console.\n\nThis feature comes from Menuboot Module.\nMenuBoot Module Created by LittlFIve.\nLastest build Time: 2023/08/24");
            /* 正在思考如何正确报错输出信息并返回WiiU Menu，以下为等待后返回代码
			OSSleepTicks(OSMillisecondsToTicks(3000));
			SYSLaunchMenu();
			*/
		}

		while(WHBProcIsRunning()) {}
	}

	return 0;
}