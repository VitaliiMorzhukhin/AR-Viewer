#include <threepp/threepp.hpp>
#include <threepp/utils/Utils.hpp>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <iostream>

using namespace threepp;

Scene scene;
std::shared_ptr<Object3D> model;
Vector3 targetPoint(0, 0, 0);

void loadModel(const std::string& path) {
    GLTFLoader loader;
    loader.load(path, [&](const GLTF& gltf) {
        model = gltf.scene;
        scene.add(model);
        model->position.copy(targetPoint);
    });
}

void setTargetPoint(float x, float y, float z) {
    targetPoint.set(x, y, z);
    if (model) {
        model->position.copy(targetPoint);
    }
}

void loop() {
    requestAnimationFrame(loop);
    Renderer::instance().render(scene, Camera::getActive());
}

int main() {
    auto& renderer = WebGLRenderer::create();
    scene = Scene::create();

    auto camera = PerspectiveCamera::create(70, renderer.getAspect(), 0.01f, 1000);
    camera->position.z = 5;
    Camera::setActive(camera);

    AmbientLight::create(0xffffff, 1)->addTo(scene);

    // default model
    loadModel("../models/model.glb");

    EM_ASM(
        document.getElementById('fileInput').onchange = function(evt) {
            let file = evt.target.files[0];
            if (file) {
                let url = URL.createObjectURL(file);
                Module.ccall('loadModel', null, ['string'], [url]);
            }
        };
    );

    loop();
    return 0;
}
