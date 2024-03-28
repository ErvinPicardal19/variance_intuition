# C++ demonstration to show the intuition of sample variance

<p align="center">
![demo](./assets/demo.gif "Cumulative Variance")
</p>

Just a simple demonstration as to why we divide the sum of each squared difference between the sum and mean by *(n-1)* rather than *n* for when sampling a population. 

### Sample variance:
## $\frac{\Sigma_{i=o}^{n} (x_i - \overline{x})^2}{n-1}$

### Population variance:
## $\frac{\Sigma_{i=o}^{n} (x_i - \mu)^2}{n}$

## Install
run `build.sh`
```bash
chmod +x ./build.sh
./build.sh

```
run `make`
```bash
cd build
make
```