#include <coreinit/debug.h>
#include <whb/proc.h>
#include <sysapp/title.h>
#include <sysapp/launch.h>

int main() {
	WHBProcInit();

	if (WHBProcIsRunning()) {
		if (
			SYSCheckTitleExists(0x0005000010132200) // 检查Id是否存在
		)
		{
			uint64_t titleId = 0x0005000010132200;  // 如果你想更改自启动游戏，请更改此条
			_SYSLaunchTitleWithStdArgsInNoSplash(titleId, nullptr);
		} else {
			OSFatal("Failed to boot the APP!\nThis Module From LittlFIve.\nCreate on 2023/08/23");
		}

		while(WHBProcIsRunning()) {}
	}

	return 0;
}