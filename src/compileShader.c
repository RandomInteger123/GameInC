#include <compileShader.h>

struct Shaders Shaders;



int compileVertexShader(const char* shaderSourcePath)
{
    char ch;
    int success = 0;
    char infoLog[512];
    FILE* file;
    i4 size;

    file = fopen(shaderSourcePath, "r");
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    char* sourceCode = (char*)malloc(size + 1);
    memset(sourceCode, 0, size);

    while(1)
    {
        ch = fgetc(file);
        if(ch != EOF)
        {
            sourceCode[success] = ch;
            success++;
        }else
        {
            break;
        }
    }

    *(sourceCode + size + 1) = '\0';
    fclose(file);
    printf("%s\n", sourceCode);

    Shaders.vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(Shaders.vertexShader, 1, (const GLchar * const*)&sourceCode, NULL);
    glCompileShader(Shaders.vertexShader);

    glGetShaderiv(Shaders.vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {Log("Shaders.vertexShader compilation failed...\n");glGetShaderInfoLog(Shaders.vertexShader, 512, NULL, infoLog); printf("%s", infoLog);}
    
    printf("%d\n\n", size);
    free(sourceCode);

}


int compileFragmentShader(const char* shaderSourcePath)
{
    char ch;
    int success = 0;
    char infoLog[512];
    FILE* file;
    i4 size;

    file = fopen(shaderSourcePath, "r");
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    char* sourceCode = (char*)malloc(size + 1);
    memset(sourceCode, 0, size + 1);

    while(1)
    {
        int count = 0;
        ch = fgetc(file);
        if(ch != EOF)
        {
            sourceCode[success] = ch;
            success++;
        }else
        {
            break;
        }
    }

    *(sourceCode + size + 1) = '\0';
    fclose(file);
    printf("%s\n", sourceCode);

    Shaders.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(Shaders.fragmentShader, 1, (const GLchar * const*)&sourceCode, NULL);
    glCompileShader(Shaders.fragmentShader);

    glGetShaderiv(Shaders.fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {Log("Shaders.fragment compilation failed...\n");glGetShaderInfoLog(Shaders.fragmentShader, 512, NULL, infoLog); printf("%s", infoLog);}
    
    printf("%d\n\n", size);
    free(sourceCode);
} 

void linkShaders()
{
    int success;
    char infoLog[512];

    Shaders.program = glCreateProgram();
    glAttachShader(Shaders.program, Shaders.vertexShader);
    glAttachShader(Shaders.program, Shaders.fragmentShader);
    glLinkProgram(Shaders.program);

    glGetProgramiv(Shaders.program, GL_LINK_STATUS, &success);
    if(!success) 
    {
        glGetProgramInfoLog(Shaders.program, 512, NULL, infoLog);
    }

    glDeleteShader(Shaders.vertexShader);
    glDeleteShader(Shaders.fragmentShader);  
}

