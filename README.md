# SwitchControllerPico

Raspberry Pi Picoを使ってNintendo Switchのゲームを自動化するマイコン用のライブラリです。

# このライブラリについて

このライブラリはinterimadd氏の[NintendoSwitchControll](https://github.com/interimadd/NintendoSwitchControll)を参考に作成しています

# 導入方法

必要なもの

    Raspberry Pi Pico 1台
    USB ケーブル 1本（Raspberry Pi Pico と Switch や PC を接続するのに必要）

動作環境

    Arduino IDE（1.8.19 推奨）
    Arduino-Pico(v2.7.1)

参考URL:https://github.com/earlephilhower/arduino-pico

# 使い方

## ライブラリのインストール

Arduinoのライブラリのあるフォルダ、C:/Users/ユーザ名/Documents/Arduino/librariesなどにこのリポジトリをダウンロードし展開する

## Raspberry Pi PicoのデバイスIDを書き換える

C:/Users/ユーザ名/AppData/Local/Arduino15/packages/rp2040/hardware/rp2040/2.7.1/board.txt内のRaspberry Pi Picoのvidとpidを設定している箇所を以下の値に書き換える

    rpipico.vid.0=0x0f0d
    rpipico.pid.0=0x0092

    rpipico.build.vid=0x0f0d
    rpipico.build.pid=0x0092

## 書き込み

1. Raspberry Pi PicoのBOOT SELボタンを押しながらPCと接続
2. RPI-RP2デバイスが認識される。フォルダは閉じる。
2. Arduino IDEを立ち上げる
3. ツール→ボード→Raspberry Pi RP2040 Board(2.7.1)→Raspberry Pi Picoを選択
4. ツール→USB Stack→Adafruit Tiny USBを選択
5. サンプルスケッチ(ファイル→スケッチ例→SwitchControllerPico→example→AutoButton)を開く
6. スケッチ→マイコンボードへ書き込む

Aボタン連打するサンプルなので、ポケモンセンターのNPCの前などで試してください

# 注意

主要な関数に関しては元のライブラリと同じように使用することができますが、使用前に初期化関数を実行する必要がありますので注意してください。

グローバル宣言

    const uint8_t desc_hid_report[] =
    {
        CUSTOM_DESCRIPTOR
    };

    Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_NONE, 2, false);

setup関数

    switchcontrollerpico_init(); ← 必須
    // wait until device mounted
    while( !TinyUSBDevice.mounted() ) delay(1); ← 必須
    switchcontrollerpico_reset(); ← 念のため

# Lisence

このプロジェクトのライセンスはMITライセンスです。詳細はLICENSEをご覧ください。
