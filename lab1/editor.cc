#include "editor.h"

#include <string>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
    if(pos >= text.size()) {
        return string::npos;
    }

    char close_par = text[pos];
    char open_par;

    if(close_par == ')') open_par = '(';
    else if(close_par == ']') open_par= '[';
    else if(close_par == '}') open_par = '{';
    else return string::npos;

    int count = 0;

    for(size_type i = pos; i-- >0;) {
        if(text[i] == close_par) {
            count++;
        } else if(text[i] == open_par) {
            if(count == 0) {
                return i;
            }

            count--;
        }
    }

    return string::npos;
}
