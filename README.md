# Modern_OpenGL_Study #

***
#### 关于： ####
> 这是我个人学习C++和OpengGL的一些Demo，在此非常感谢 [Joey de Vries](https://joeydevries.com/#home)提供的[OpengGL学习教程](https://learnopengl.com/)。

此README文件也对各小结的学习作了简单总结。类容在不停更新中。

## 文件夹 ##
* ./MyLib 依赖库以及头文件。
* ./Demo_Done 我完成的demo，可以直接在window平台下运行，当然显卡需要支持OpenGL3.3及以上。
* ./Deme_Code 原码文件夹。

## 环境 ##
* 此示例是在*Visual Studio 2017*下编译完成。
* 依赖库*GLFW*、*GLAD*、*GLM*、*irrKlang*、*freetype*、*stb_image*。当然如果某库不能在你系统上正常链接可以到原[教程](https://learnopengl.com/)里找到相应的库源码，Cmake后编译后食用。
* 当然此示例是使用OpenGL的**CORE_PROFILE**，即完全是通过shader，可编程管线完成的。所以你的显卡可能至少需要支持OpenGL3.3。

## 目录 ##
* [My_001_FirstOpenGLProject](https://github.com/tj41694/OpenGL#firstopenglproject)
* [My_002_triangle](https://github.com/tj41694/OpenGL#triangle)
* [My_003_shader](https://github.com/tj41694/OpenGL#shader)
* [My_004_textures](https://github.com/tj41694/OpenGL#textures)
* [My_005_transform](https://github.com/tj41694/OpenGL#transform)
* [My_006_coordinate](https://github.com/tj41694/OpenGL#coordinate)
* [My_007_camera](https://github.com/tj41694/OpenGL#camera)
* [My_008_color](https://github.com/tj41694/OpenGL#color)
* [My_009_basicLighting](https://github.com/tj41694/OpenGL#basiclighting)
* [My_010_materials](https://github.com/tj41694/OpenGL#materials)
* [My_011_lightMaps](https://github.com/tj41694/OpenGL#lightmaps)
* [My_012_lightCasters](https://github.com/tj41694/OpenGL#lightcasters)
* [My_013_multibleLights](https://github.com/tj41694/OpenGL#multiblelights)
* [My_014_meshModel](https://github.com/tj41694/OpenGL#meshmodel)
* [My_015_depthTest](https://github.com/tj41694/OpenGL#depthtest)
* [My_016_stencilTest](https://github.com/tj41694/OpenGL#stenciltest)
* [My_017_alpha](https://github.com/tj41694/OpenGL#alpha)
* [My_018_framebuffers](https://github.com/tj41694/OpenGL#framebuffers)
* [My_019_cubemaps](https://github.com/tj41694/OpenGL#cubemaps)
* [My_020_geometryShader](https://github.com/tj41694/OpenGL#geometryshader)
* [My_021_DrawInstance](https://github.com/tj41694/OpenGL#drawinstance)
* [My_022_MSAA](https://github.com/tj41694/OpenGL#msaa)
* [My_023_Blinn](https://github.com/tj41694/OpenGL#blinn)
* [My_024_shadowMaping](https://github.com/tj41694/OpenGL#shadowmaping)
* [My_025_Point_Shadows](https://github.com/tj41694/OpenGL#point_shadows)
* [My_026_text_rend](https://github.com/tj41694/OpenGL#text_rend)

***
## FirstOpenGLProject
OpenGL的运行需要一个窗口环境，我们这里使用GLFW。同时我们需要知道硬件商提供给我们的OpenGL的借口函数指针。我们可以手动取得，当然我们也可以使用GLEW/GLAD来简化这个过程，在这里我们使用GLAD。所以，我我们的GL运行环境为GLFW+GLAD。
## triangle
我们先初始化GLFW,configure GLFW，然后初始化 GLAD；
然后告诉OpenGL我们需要渲染多大窗口尺寸。

	glViewport(0, 0, 800, 600);
当然最好是通过GLFW的回调函数，来决定需要渲染的尺寸大小。
还有一点，GLFW已经帮我们配置好了双缓冲。说以我们在render Loop里的最好告诉glfw我们需要交换缓冲：
	
	glfwSwapBuffers(window);

当然我们需要在渲染循环里输入一些指令需要声明并定义一个输入函数：

	glfwSwapBuffers(window);

## shader
shader 是着色器语言的统称，是运行在显卡上的一小段程序。目前流行的有DX的HLSL,和OpenGL的GLSL。
sshader的运行过程：

![](https://learnopengl-cn.github.io/img/01/04/pipeline.png)

我们可以指定的有vertex shader、geometry shader、fragment shader，其中vertex shader与fragment shader必须指定。

shader 的编译链接有很多细节，当我们熟悉了之后可以包装成一个Shader类，以抽象掉细节。

宁外补充一句，OpenGL可以接受的顶点数据为任意float，但是只有在（-1，1）中的才会被渲染。（-1，1）中的部分会被投影到我们指定的窗口中

	glViewport(0, 0, 800, 600);

如果我们没有指定projection matrix 我们渲染的图像由于是800：600所以看上去是变形了的。


## textures

纹理是提升画面细节最重要的元素，没有之一！

我们通过第三方库（stb_image）将纹理加到到内存，并通过glTexImage2D函数传输给当前绑定的texture对象。这样就完成了纹理传输要显卡的过程，当我们下次想使用此纹理时，再次绑定纹理对象至GL_TEXTURE_2D即可。当然过程中也需要设置多个纹理参数。

当熟悉整个过程之后，我们也会将整个过程的细节包装成一个Textur类，抽象掉细节。


## transform

此节类容大部分为线性代数知识，如果大学没学好，可以到这里补救。[YouTube](https://www.youtube.com/watch?v=kjBOesZCoqc&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)、[B站](http://space.bilibili.com/88461692#!/channel/detail?cid=9450)。
我们必须了解线性代数的几何意义，尤其是矩阵乘以向量的意义。不多说，上面的视频看完，觉得大学线代学的只是如何做计算题而已- -！

补救完线代，那么我们是时候拿出我们的库了。


[GLM](http://glm.g-truc.net/0.9.5/index.html)可以是是GL的官方库了，值得注意的是我们使用0.9.5版本就行，据说高版本的矩阵初始化如：

	glm::mat4 trans;

初始化后并不是单位矩阵，不知道GLM是如何考量的。还有一点挺遗憾，此官网需要带上梯子才能上。

## coordinate

坐标系统也充分需要我们理解矩阵的意义。

三个矩阵

* mode matrix，是一个负责移动的矩阵，将object在整个世界空间（float）范围移来移去；
* view matrix 可以理解为相机矩阵，OpenGL并没有camera概念，只是将整个世界的坐标通过这个矩阵来变换，让我们觉得像是在使用相机，其实OpenGL的视口永远没变都是在(-1,1)之间。 view matrix说错的不是我是世界！
* projection matrix 剪裁矩阵，一般就两选择，正交或透视。我们之前说的渲染画面比例不对会变形就可以通过这个矩阵来修正。

三个矩阵都可以通过GLM库来获取。

## camera

主要是通过修改view matrix来实现摄像机。主要是GLM的glm::lookAt函数来配置。我们可以通过鼠标和WSAD键来控制camera，我们看上去建立了一个第一人称camera。

我们将需要的数据都包装成一个camera类，这样我们设置view，和projection矩阵时就库通过这个类成员来设置。

## color
我们通过fragment shader的配置，实现了连个只有单色的box。

## basicLighting
我们就像之前配置vertex shader的三个矩阵实现了camera功能，在这里我们通过分解与简化了真实世界的物理光照，通过一个单一环境光照(Ambient Lighting)，模拟真实世界的GI（全局光，来自天光，物体的相互反色光线）；来自光源的照明：漫反射光照(Diffuse Lighting)；来自光源的高光：镜面光照(Specular Lighting)目前使用的冯氏模型。

然后我们在fragment里把几种结果相加：

	vec3 result = (ambient + diffuse + specular) * objectColor;

![](https://learnopengl-cn.github.io/img/02/02/basic_lighting_phong.png)

当然其中，除了ambient light比较简单外，其他两种光线都是通过，摄像机位置、光源位置，fragment位置，计算得来，值得注意的是冯氏模型的高光计算是通过GLM自带函数glm::pow()计算。

## materials
目前我们的BOX都是单色的，而现实世界各个物体的漫反射颜色不一样，对光源的高光属性也不一样，那么这一节我们就将再给fragment shader加料，我们给不同物体不同的，漫反射以及高光属性，使用

	struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
	};

	uniform Material material;

使用一个结构体传递给shader，再在之前的光照中加入这些属性。

## lightMaps
我们将纹理加加入fragment shader，实现类似Vray里的高光贴图效果。

![](https://learnopengl-cn.github.io/img/02/04/materials_specular_map.png)
## lightCasters
我们实现了平行光、点光源，带衰减参数、聚光效果。
这一节值得注意的是衰减的公式，

	Fatt=1.0Kc+Kl∗d+Kq∗d2

真是的物理情况是光的衰减应该是与距离成平方反比，但这里我们用了函数来修正，这是因为早期OpenGL并没有gamma校正，如果我们使用gamma校正，我们再使用平方反比来对光线经行衰减处理，会显得非常真实。

## multibleLights

整合多种光源到一个场景。

![](https://learnopengl-cn.github.io/img/02/06/multiple_lights_combined.png)


## meshModel
我们通过三方库Assimp（这名字相当好记）。。。
加载外部多格式模型至Opengl能识别的数据，并包装成一个名为Modle的类。作者原话是与箱子说再见！

![](https://learnopengl-cn.github.io/img/03/03/model_diffuse.png)
## depthTest
深度缓冲是实现天空盒的重要类容。
## stencilTest
## alpha
* 我们可以在fragment中，设置一定的条件选择性丢弃片段以实现完全透明的效果：

	    if(texColor.a < 0.1)
        discard;
*	blend 即半透明这个很简单；

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	我们启用半透明，并设置好半透明参数即可。

值得注意的是，因为Opengl通过深度测试会丢弃看不到的fragment，的绘制顺序在半透明里就显得格外重要，得先绘制远处再绘制近处。那么我们就可以使用std::map的一个反向迭代器(Reverse Iterator)对渲染的半透明窗户经行排序。

## framebuffers
## cubemaps
## geometryShader
## DrawInstance
## MSAA
## Blinn
## shadowMaping
## Point_Shadows
## text_rend


