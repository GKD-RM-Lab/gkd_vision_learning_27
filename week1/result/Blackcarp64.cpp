#include <cmath>
#include <iostream>
#include <climits>

int main()
{
    int x = 320;
    int y = 240;
    char command;
    int distance;
    int colors[100];
    int lefts[100];
    int tops[100];
    int widths[100];
    int heights[100];

    int detection_count = 0;

    while (true)
    {
        std::cin >> command;

        if (command == 'q')
        {
            break;
        }

        if (command == 'x')
        {
            int color;
            int left;
            int top;
            int width;
            int height;

            std::cin >> color >> left >> top >> width >> height;

            colors[detection_count] = color;
            lefts[detection_count] = left;
            tops[detection_count] = top;
            widths[detection_count] = width;
            heights[detection_count] = height;

            detection_count++;

            int best_index = -1;
            int best_distance = INT_MAX;
            int best_area = -1;

            for (int i = 0; i < detection_count; ++i)
            {
                int area = widths[i] * heights[i];

                if (colors[i] == 1 && area >= 400)
                {
                    int candidate_x = lefts[i] + widths[i] / 2;
                    int candidate_y = tops[i] + heights[i] / 2;

                    int delta_x = candidate_x - x;
                    int delta_y = candidate_y - y;

                    int manhattan_distance = std::abs(delta_x) + std::abs(delta_y);

                    if (
                        manhattan_distance < best_distance
                        || (manhattan_distance == best_distance && area > best_area)
                    )
                    {
                        best_distance = manhattan_distance;
                        best_index = i;
                        best_area = area;
                    }
                }
            }

            if (best_index == -1)
            {
                std::cout << "无有效目标\n";
            }
            else
            {
                int best_x = lefts[best_index] + widths[best_index] / 2;
                int best_y = tops[best_index] + heights[best_index] / 2;
                int best_delta_x = best_x - x;
                int best_delta_y = best_y - y;

                std::cout << "最近敌方装甲板: ("
                          << best_x << ", " << best_y
                          << "), 距离: " << best_distance
                          << ", 调整: [";

                bool has_instruction = false;

                if (best_delta_x < 0)
                {
                    std::cout << "a " << std::abs(best_delta_x);
                    has_instruction = true;
                }
                else if (best_delta_x > 0)
                {
                    std::cout << "d " << best_delta_x;
                    has_instruction = true;
                }

                if (best_delta_y != 0)
                {
                    if (has_instruction)
                    {
                        std::cout << ", ";
                    }

                    if (best_delta_y < 0)
                    {
                        std::cout << "w " << std::abs(best_delta_y);
                    }
                    else
                    {
                        std::cout << "s " << best_delta_y;
                    }
                }

                std::cout << "]\n";
            }
            continue;
        }

        std::cin >> distance;

        if (command == 'w')
        {
            y -= distance;
        }

        if (command == 's')
        {
            y += distance;
        }

        if (command == 'a')
        {
            x -= distance;
        }

        if (command == 'd')
        {
            x += distance;
        }

        if (x < 0) x = 0;
        if (x > 639) x = 639;
        if (y < 0) y = 0;
        if (y > 479) y = 479;

        std::cout << "准星: (" << x << ", " << y << ")\n";
    }

    return 0;
}
