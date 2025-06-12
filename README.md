# AR Viewer

This repository provides a minimal Web AR viewer. The root `index.html` loads a GLB model with [three.js](https://threejs.org/). A C++ implementation using [threepp](https://github.com/markaren/threepp) lives in the `cpp` directory and can be compiled to WebAssembly with Emscripten.

## GitHub Pages Deployment

A GitHub Actions workflow in `.github/workflows/pages.yml` builds the C++ example and publishes the static files to GitHub Pages whenever the `main` branch is updated. After the workflow completes you can open the deployed site from the URL shown in the workflow logs.

## Building the C++ Example Locally

1. Install [Emscripten](https://emscripten.org/docs/getting_started/downloads.html).
2. Run `cd cpp && ./build.sh` to compile the viewer.
3. Serve the generated files in `cpp/build` with any static web server.

The HTML viewer in the repository loads `models/model.glb` by default. You can replace this file or point the code to another path.
