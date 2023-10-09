#include <GL/glu.h>
#include "GLFW/glfw3.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>

GLFWwindow *window;

int main()
{


    glfwInit();

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(500, 800, "SpaceInfarders", NULL, NULL);

    glfwSwapInterval(1);

    glfwMakeContextCurrent(window);

    start:

    int windowWidth, windowHeigth;

    float x = 0;
    float y = 0;

    float by = 0;
    float bc = 0.0;

    float ex = 0;

    float alphaone = 1.0;
    float alphatwo = 1.0;
    float alphathree = 1.0;
    float alphafour = 1.0;
    float alphafive = 1.0;

    double previousTime = glfwGetTime();
    int frameCount = 0;
    double lasttime = glfwGetTime();


    while (!glfwWindowShouldClose(window))

    {

        while (glfwGetTime() < lasttime + 1.0 / 2000)
        {
            // TODO: Put the thread to sleep, yield, or simply do nothing
        }
        lasttime += 1.0 / 2000;

        // Measure speed
        double currentTime = glfwGetTime();
        frameCount++;
        // If a second has passed.
        if (currentTime - previousTime >= 1.0)
        {
            // Display the frame count here any way you want.
            std::cout << "FPS: " << frameCount << std::endl;

            frameCount = 0;
            previousTime = currentTime;
        }

        glfwGetWindowSize(window, &windowWidth, &windowHeigth);

        glMatrixMode(GL_PROJECTION);
        glViewport(0, 0, windowWidth, windowHeigth);
        glLoadIdentity();
        gluOrtho2D(0, windowWidth, 0, windowHeigth);

        if (glfwGetKey(window, GLFW_KEY_D))
        {
            x += 0.1;
        }

        if (glfwGetKey(window, GLFW_KEY_A))
        {
            x -= 0.1;
        }

        if (glfwGetKey(window, GLFW_KEY_W))
        {
            y += 0.1;
        }

        if (glfwGetKey(window, GLFW_KEY_S))
        {
            y -= 0.1;
        }

        if (glfwGetKey(window, GLFW_KEY_SPACE))
        {
            bc = 1.0;
            by += 0.5;
        }
        else
        {
            bc = 0.0;
            by -= by;
            by = 0;
        }

        if (y + by >= 300 and y <= 310 and x + 25 >= ex and x <= ex + 35 and bc == 1.0)
        {
            alphaone = 0.0;
        }
        if (y + by >= 300 and y + by <= 310 and x + 25 >= 100 + ex and x <= 135 + ex and bc == 1.0) {
            alphatwo = 0.0;
        }
        if (y + by >= 300 and y + by <= 310 and x + 25 >= 200 + ex and x <= 235 + ex and bc == 1.0) {
            alphathree = 0.0;
        }
        if (y + by >= 300 and y + by <= 310 and x + 25 >= 300 + ex and x <= 335 + ex and bc == 1.0) {
            alphafour = 0.0;
        }
        if (y + by >= 300 and y + by <= 310 and x + 25 >= 400 + ex and x <= 435 + ex and bc == 1.0) {
            alphafive = 0.0;
        }
        
        if (alphaone == 0.0 and alphatwo == 0.0 and alphathree == 0.0 and alphafour == 0.0 and alphafive == 0.0)
        {
            goto start;
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(0.0, 0.0, 0.0, 1.0);

        glBegin(GL_POLYGON); // Character Sprite

        glColor4f(0.0, 1.0, 0.0, 1.0);
        glVertex2f(25 + x, 75 + y);
        glVertex2f(50 + x, 100 + y);
        glVertex2f(75 + x, 75 + y);

        glEnd();

        glBegin(GL_POLYGON); // Bullet Sprite

        glColor4f(bc, bc, bc, bc);
        glVertex2f(45 + x, 105 + y + by);
        glVertex2f(45 + x, 120 + y + by);
        glVertex2f(50 + x, 120 + y + by);
        glVertex2f(50 + x, 105 + y + by);

        glEnd();

        glBegin(GL_POLYGON); // Enemy Sprite1

        glColor4f(alphaone, alphaone, alphaone, alphaone);
        glVertex2f(25 + ex, 425);
        glVertex2f(50 + ex, 450);
        glVertex2f(75 + ex, 425);

        glEnd();

        glBegin(GL_POLYGON); // Enemy Sprite2

        glColor4f(alphatwo, alphatwo, alphatwo, alphatwo);
        glVertex2f(125 + ex, 425);
        glVertex2f(150 + ex, 450);
        glVertex2f(175 + ex, 425);

        glEnd();

        glBegin(GL_POLYGON); // Enemy Sprite3

        glColor4f(alphathree, alphathree, alphathree, alphathree);
        glVertex2f(225 + ex, 425);
        glVertex2f(250 + ex, 450);
        glVertex2f(275 + ex, 425);

        glEnd();

        glBegin(GL_POLYGON); // Enemy Sprite4

        glColor4f(alphafour, alphafour, alphafour, alphafour);
        glVertex2f(325 + ex, 425);
        glVertex2f(350 + ex, 450);
        glVertex2f(375 + ex, 425);

        glEnd();

        glBegin(GL_POLYGON); // Enemy Sprite5

        glColor4f(alphafive, alphafive, alphafive, alphafive);
        glVertex2f(425 + ex, 425);
        glVertex2f(450 + ex, 450);
        glVertex2f(475 + ex, 425);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
