#include "../system.h"

int main() {
  fprint_in_color("Color: Black; Code name: BLACK; Number color: 0.\n", BLACK, stdout);
  fprint_in_color("Color: Red; Code name: RED; Number color: 1.\n", RED, stdout);
  fprint_in_color("Color: Green; Code name: GREEN; Number color: 2.\n", GREEN, stdout);
  fprint_in_color("Color: Yellow; Code name: YELLOW; Number color: 3.\n", YELLOW, stdout);
  fprint_in_color("Color: Blue; Code name: BLUE; Number color: 4.\n", BLUE, stdout);
  fprint_in_color("Color: Magenta; Code name: MAGENTA; Number color: 5.\n", MAGENTA, stdout);
  fprint_in_color("Color: Cyan; Code name: CYAN; Number color: 6.\n", CYAN, stdout);
  fprint_in_color("Color: White; Code name: WHITE; Number color: 7.\n\n", WHITE, stdout);

  fprint_in_color("Color: Bright Black; Code name: BRIGHTBLACK; Number color: 8.\n", BLACK, stdout);
  fprint_in_color("Color: Bright Red; Code name: BRIGHTRED; Number color: 9.\n", RED, stdout);
  fprint_in_color("Color: Bright Green; Code name: BRIGHTGREEN; Number color: 10.\n", GREEN, stdout);
  fprint_in_color("Color: Bright Yellow; Code name: BRIGHTYELLOW; Number color: 11.\n", YELLOW, stdout);
  fprint_in_color("Color: Bright Blue; Code name: BRIGHTBLUE; Number color: 12.\n", BLUE, stdout);
  fprint_in_color("Color: Bright Magenta; Code name: BRIGHTMAGENTA; Number color: 13.\n", MAGENTA, stdout);
  fprint_in_color("Color: Bright Cyan; Code name: BRIGHTCYAN; Number color: 14.\n", CYAN, stdout);
  fprint_in_color("Color: Bright White; Code name: BRIGHTWHITE; Number color: 15.\n\n", WHITE, stdout);

  return 0;
}
