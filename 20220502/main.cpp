#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "OpenGL32")




static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}


class Player {
    
    
public:
    float posX, posY;
    float size;
    bool isJump;

    Player() {
        posX = 0.5f;
        posY = 0.5f;
        size = 0.3f;
        isJump = false;
    }

    void draw() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 1);
        glVertex3f(posX - size/2, posY - size/2, 0.0f);
        glVertex3f(posX + size / 2, posY - size / 2, 0.0f);
        glVertex3f(posX + size / 2, posY + size / 2, 0.0f);
        glVertex3f(posX - size / 2, posY - size / 2, 0.0f);
        glVertex3f(posX - size / 2, posY + size / 2, 0.0f);
        glVertex3f(posX + size / 2, posY + size / 2, 0.0f);
        glEnd();
    }
};

Player p1;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_R && action == GLFW_PRESS)
        system("cls");
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        p1.posX += 0.03f;
    else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        p1.posX -= 0.03f;
    else if(key == GLFW_KEY_UP && action == GLFW_PRESS)
        p1.posY += 0.03f;
    else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        p1.posY -= 0.03f;
}

class Box {

public:
    float posX, posY;
    float size;

    Box() {
        posX = 0.1f;
        posY = 0.1f;
        size = 0.2f;
    }

    void draw() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glBegin(GL_TRIANGLES);
        glColor4f(0.0f, 0.0f, 1.0f, 1);
        glVertex3f(posX - size / 2, posY - size / 2, 0.0f);
        glVertex3f(posX + size / 2, posY - size / 2, 0.0f);
        glVertex3f(posX + size / 2, posY + size / 2, 0.0f);
        glVertex3f(posX - size / 2, posY - size / 2, 0.0f);
        glVertex3f(posX - size / 2, posY + size / 2, 0.0f);
        glVertex3f(posX + size / 2, posY + size / 2, 0.0f);
        glEnd();
    }
};

void isCollision(Player pl, Box bo) {
    if (bo.posX - bo.size / 2 < pl.posX + pl.size / 2 && bo.posX + bo.size / 2 > pl.posX - pl.size / 2) {
        if (bo.posY - bo.size / 2 < pl.posY + pl.size / 2 && bo.posY + bo.size / 2 > pl.posY - pl.size / 2)
            printf("Ãæµ¹!\n");
    }
}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    
    Box b1;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.3f, 0.3f, 0.3f, 1);
        glClear(GL_COLOR_BUFFER_BIT);


        p1.draw();
        b1.draw();

        isCollision(p1, b1);

       
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}