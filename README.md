# philosophers

## 説明
このphilosopersはC言語にて「食事する哲学者」の問題を解く課題です。
mutexとsemaphoreを使用したマルチスレッド/マルチプロセスプログラミングを用いています。

## 課題要件
gcc または Clang
GNU Make

## 特徴
philo -> スレッドとミューテックスを用いて食事する哲学者を実装する。

## 実行方法
```
git clone https://github.com/hohnuki/philosopers
cd philosopers
cd philo
```

```
./philo 4 800 200 200
./philo 3 410 200 200
./philo [NUM_PHILO] [DIE_TIME] [EAT_TIME] [SLEEP_TIME]
```
