import optuna
import subprocess
from subprocess import PIPE

def objective(trial):
    x = trial.suggest_discrete_uniform('x', 2, 8, 1)
    res = 0
    n_iter = 100
    for i in range(n_iter):
        cmd = "./a.out "+f"< tools/in/{i:04}.txt "+str(x)
        proc = subprocess.run(cmd, shell=True, stdout=PIPE, stderr=PIPE, text=True)
        d = proc.stderr
        res += int(d)
    return res / n_iter

def main():
    subprocess.run("clang++ -std=c++17 main.cpp", shell=True)
    study = optuna.create_study()
    study.optimize(objective, n_trials=30, n_jobs=1)
    print(len(study.trials))
    print(study.best_params)

if __name__ == '__main__':
    main()