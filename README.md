# Example of using the Mimic1 Libraries

This is a small example using the Mimic1 libraries.

## Setup Mimic1

This assumes mimic1 has been installed on your system, for full instructions
see the [Mimic1-repo](https://github.com/MycroftAI/mimic1), but in short it
should be

```
git clone https://github.com/MycroftAI/mimic1
cd mimic1
./dependencies.sh
./autogen.sh
mkdir build && cd build
../configure
make
make install
```

## Building the example

To build the `mimic_example` application run

```
mkdir build && cd build
cmake ..
make
```

## Launching the application

The application takes two arguments, the sentence and the voice file to use:

Example:
```
./mimic_example "This is using the mimic libraries" /PATH/TO/mimic/voicescmu_us_slt.flitevox
```
