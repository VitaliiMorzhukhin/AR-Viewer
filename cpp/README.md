# C++ Web AR Viewer

This folder contains an example of a very basic AR viewer written in C++ for the web. It uses the [threepp](https://github.com/markaren/threepp) library (a C++ port of three.js) and is intended to be compiled with Emscripten.

The viewer loads a GLB model and allows setting a base point (target point). The model can be replaced by selecting another file through an HTML file input.

## Building

1. Install [Emscripten](https://emscripten.org/docs/getting_started/downloads.html).
2. Install the `threepp` library. You can fetch it with CMake or add it manually.
3. Build using CMake:

```bash
mkdir build
cd build
emcmake cmake ..
cmake --build .
```

This should produce `index.html`, `main.js` and `main.wasm` that can be served with any static web server.

## Running

Serve the resulting files via a local web server. Open the page in a browser that supports WebXR to view the model in AR.

The HTML page should contain an element with `id="fileInput"` for selecting models.
