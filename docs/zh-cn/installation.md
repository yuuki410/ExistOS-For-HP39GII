---
title: ExistOS 安装教程
---

## Windows 用户

### ExistOS Updater 刷入

如果您是 Windows 用户，您可以直接[从此处下装 ExistOS Updater](https://github.com/ExistOS-Team/ExistOS_Updater_v2/releases) 然后参考[此教程](https://github.com/ExistOS-Team/ExistOS_Updater_v2#readme)进行傻瓜式安装。

最新的已编译固件可从[此处下载](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/releases)。

![screenshot](https://github.com/ExistOS-Team/ExistOS_Updater_v2/blob/master/image/screenshot1.png)

### 手动刷入

若无法正常运行上述程序，请参考下面的 Linux 用户教程，并略去三个编译工具过程：

- 下载 [edb.exe](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/blob/main/tools/edb.exe) 代替 `edb-unix`
- 下载 [sb_loader.exe](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/blob/main/tools/sbtools_win/sb_loader.exe) 代替 `sb_loader`
- 下装 [sysigner.exe](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/blob/main/tools/sysigner.exe) 代替 `sysigner`

## Linux 用户

### 准备刷写工具

您需要安装以下 C/C++ 库然后才能编译工具：

- [Crypto++](https://cryptopp.com/wiki/Linux#Distribution_Package)
- libusb (1.0)

[下载本仓库源代码](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/archive/refs/heads/main.zip)，然后编译下面几个目录：

- `tools/sbtools`
- `tools/sys_signer`

[下载 edb-unix 源代码](https://github.com/ExistOS-Team/edb-unix)并编译。

[下载固件](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/releases)。

将固件于编译好的二进制文件放在同一目录下，或者你需要输入相对路径/绝对路径。

### 刷入系统

先将 OSLoader 载入计算器 RAM：

```bash
# 你需要卸下计算器的所有电池（完全断电），按住 ON/C 键然后连上 USB 线以进入刷写模式
# Windows 系统下可以查看设备管理器是否出现一个名为 “USB 输入设备” 且 ID 为 066F:3770 的 USB HID 设备
./sb_loader -f OSLoader.sb
```

![USBID](../Image/0.png)

随后计算器应开机并显示“No System Installed”：

![OSL Boot](../Image/1.png)

将 OSLoader 写入 Flash 引导区：

```bash
# edb 需要挂载 USB 设备才能连接计算器
sudo ./edb -r -s -f OSLoader.sb 1408 b
```

计算器将自动重启，现在将 ExistOS 写入计算器：

```bash
sudo ./edb -r -s -f ExistOS.sys 1984
```

然后就可以使用 ExistOS 了！
