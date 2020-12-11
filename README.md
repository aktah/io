# io

[![sampctl](https://img.shields.io/badge/sampctl-io-2f2f2f.svg?style=for-the-badge)](https://github.com/aktah/io)

## วิธีติดตั้ง

ถ้าหากคุณใช้ sampctl:

```bash
sampctl package install aktah/io
```

ลำดับการวาง Include:

- จำเป็นต้องมี [Pawn.RakNet](https://github.com/katursis/Pawn.RakNet)

```pawn
#include <Pawn.RakNet>
#include <io> // ไว้ใต้ Pawn.RakNet เสมอ

#define cec_auto
#include <cec>        // aktah/cec | ใช้ควบคู่กับ cec ได้ด้วยนะ ถ้ามีก็เอามาไว้ใต้ io ได้เลย (ทำให้ข้อความส่วนใหญ่ที่เห็นภายในเซิร์ฟเวอร์ไม่เพี้ยน)
```