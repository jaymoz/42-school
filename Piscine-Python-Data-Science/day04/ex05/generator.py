import sys
import psutil


def generator(path):
    with open(path, 'r')as f:
        for line in f:
            yield line

if __name__ == '__main__':
    if len(sys.argv) == 2:
        for line in generator(sys.argv[1]):
            pass
        mem = psutil.Process().memory_info().vms / 2 ** 30
        cpu = psutil.Process().cpu_times()
        print(f'Peak Memory Usapmemge = {mem:.3f} Gb')
        print(f'User Time + System Time = {cpu.user + cpu.system:.2f}s')

