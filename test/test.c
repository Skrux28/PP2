//
// Created by 12254 on 2022/5/22.
//
#include "../CUnit/Basic.h"
#include "../game.h"
#include "../initial.h"

static int suite_init(void)
{
    return 0;
}

static int suite_clean(void)
{
    return 0;
}

static void test_loadFile(void)
{
    FILE *file = NULL;
    pBoard pb = NULL;
    FILE *file1 = fopen("../game.txt","r");
    pBoard pb1 = malloc(sizeof (Board));
    CU_ASSERT_EQUAL(loadFile(file, pb), -1);
    CU_ASSERT_EQUAL(loadFile(file, pb1), -1);
    CU_ASSERT_EQUAL(loadFile(file1, pb), -1);
    CU_ASSERT_EQUAL(loadFile(file1, pb1), 0);
}

static  void test_Put_button(void){
    SDL_Renderer *render = NULL;
    SDL_Window *window = SDL_CreateWindow("The game of life",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000, SDL_WINDOW_SHOWN);
    SDL_Renderer *render1 = SDL_CreateRenderer(window,-1,0);
    int win_w = -1;
    int win_w1 = 1000;
    int win_h = -1;
    int win_h1 = 600;
    char* button_img = NULL;
    char* button_img1 = "../img/edit.png";
    int index = -1;
    int index1 = 0;
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h1, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h1, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h1, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h1, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h1, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h1, button_img, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h1, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h1, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h1, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h1, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w, win_h1, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h1, button_img1, index),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w, win_h1, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render, win_w1, win_h1, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h, button_img1, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h1, button_img, index1),-1);
    CU_ASSERT_EQUAL(Put_button(render1, win_w1, win_h1, button_img1, index1),0);
}

static void test_runGame(void){
    pBoard pb = NULL;
    pBoard pb1 = malloc(sizeof (Board));
    FILE *file1 = fopen("../game.txt","r");
    loadFile(file1, pb1);
    CU_ASSERT_EQUAL(runGame(pb),-1);
    CU_ASSERT_EQUAL(runGame(pb1),0);
}

static void test_Clean_board(void){
    pBoard pb = NULL;
    pBoard pb1 = malloc(sizeof (Board));
    FILE *file1 = fopen("../game.txt","r");
    loadFile(file1, pb1);
    CU_ASSERT_EQUAL(Clean_board(pb),-1);
    CU_ASSERT_EQUAL(Clean_board(pb1),0);
}

static void test_Random_board(void){
    pBoard pb = NULL;
    pBoard pb1 = malloc(sizeof (Board));
    FILE *file1 = fopen("../game.txt","r");
    loadFile(file1, pb1);
    CU_ASSERT_EQUAL(Random_board(pb),-1);
    CU_ASSERT_EQUAL(Random_board(pb1),0);
}

static void test_Count_alive(void){
    pBoard pb = NULL;
    pBoard pb1 = malloc(sizeof (Board));
    FILE *file1 = fopen("../game.txt","r");
    loadFile(file1, pb1);
    CU_ASSERT_EQUAL(Count_alive(pb),-1);
    CU_ASSERT_EQUAL(Count_alive(pb1),0);
}

static void test_history_save(void){
    FILE *file = NULL;
    pBoard pb = NULL;
    FILE *file1 = fopen("../history.txt","r");
    FILE *file2 = fopen("../game.txt","r");
    pBoard pb2 = malloc(sizeof (Board));
    loadFile(file2, pb2);
    CU_ASSERT_EQUAL(history_save(file, pb), -1);
    CU_ASSERT_EQUAL(history_save(file, pb2), -1);
    CU_ASSERT_EQUAL(history_save(file1, pb), -1);
    CU_ASSERT_EQUAL(history_save(file1, pb2), 0);
}


static void test_window_text(void){
    TTF_Font * ttf_font = NULL;
    TTF_Font * ttf_font1 = TTF_OpenFont("../font/Roboto-Light.ttf", 15);
    SDL_Renderer *render = NULL;
    SDL_Window *window = SDL_CreateWindow("The game of life",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000, SDL_WINDOW_SHOWN);
    SDL_Renderer *render1 = SDL_CreateRenderer(window,-1,0);
    int win_w = -1;
    int win_w1 = 1000;
    char* sum = NULL;
    char* sum1 = "well";
    int x1 = -1;
    int x = 0;
    int y = -1;
    int y1 = 1;
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x1, y, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render, sum1, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font, render1, sum1, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render, sum1, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum, x1, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x, y1, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x1, y, win_w1), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x1, y1, win_w), -1);
    CU_ASSERT_EQUAL(window_text(ttf_font1, render1, sum1, x1, y1, win_w1), -1);

}

static CU_TestInfo tests[] = {
        { "test_loadFile", test_loadFile },
        {"test_Put_button",test_Put_button},
        {"test_runGame",test_runGame},
        {"test_Clean_board",test_Clean_board},
        {"test_Random_board",test_Random_board},
        {"test_Count_alive",test_Count_alive},
        {"test_history_save",test_history_save},
        {"test_window_text",test_window_text},
        CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
        { "suite_sum", suite_init, suite_clean, NULL, NULL, tests },
        CU_SUITE_INFO_NULL,
};

int main()
{
    CU_pSuite pSuite = NULL;

    // initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Register suites
    if (CUE_SUCCESS != CU_register_suites(suites)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up registry and return
    CU_cleanup_registry();
    return CU_get_error();
}