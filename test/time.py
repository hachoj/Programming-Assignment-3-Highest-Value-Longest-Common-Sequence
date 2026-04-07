import subprocess
import time

import matplotlib.pyplot as plt

input_files = [f"data/test{i}.in" for i in range(10)]
runtimes = []

for f in input_files:
    with open(f) as stdin:
        start = time.perf_counter()
        subprocess.run(["./hvlcs"], stdin=stdin, capture_output=True)
        end = time.perf_counter()
    runtimes.append(end - start)

plt.bar(range(10), runtimes)
plt.title("HVLCS Runtime Graph")
plt.xlabel("Test Case")
plt.ylabel("Runtime (s)")
plt.savefig("out/hvlcs_runtime.png")
