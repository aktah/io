# io

[![sampctl](https://img.shields.io/badge/sampctl-io-2f2f2f.svg?style=for-the-badge)](https://github.com/aktah/io)

## วิธีติดตั้ง

ถ้าหากคุณใช้ sampctl:

```bash
sampctl package install aktah/io
```

```pawn
#include <io>
#include <cec> // aktah/cec | ถ้าใช้ cec แก้สีด้วยก็เอาไว้ใต้ io

// ตัวอย่าง
public OnPlayerConnect(playerid)
{
    if(isPlayerAndroid(playerid))
    {
        SendClientMessage(playerid, -1, "คุณเข้าสู่ระบบผ่านมือถือ");
    }
}
```
