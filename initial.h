//
// Created by 12254 on 2022/5/14.
//

#ifndef PP2_INITIAL_H
#define PP2_INITIAL_H
int loadFile(char* filename, Board * pb);
int window_text(TTF_Font* ttf_font, SDL_Renderer *render, char *sum, int x, int y, int win_w);
int Put_button(SDL_Renderer *render, int win_w, int win_h, char *button_img, int index);
#endif //PP2_INITIAL_H
