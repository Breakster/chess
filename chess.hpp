#include <vector>
#include <memory>

namespace chess {
const int size = 8;

struct pos {
    int x;
    int y;
};

enum class color {white, black};

class piece {
    const enum color color;
public:
    explicit piece(enum color c): color(c) {}
    virtual ~piece () {}
    // Could move on an empty board
    virtual bool could_move(pos from, pos to) =0;
    virtual char repr() =0;
};

typedef std::shared_ptr<piece> piece_p;

class pawn : public piece {
public:
    using piece::piece;
    bool could_move(pos from, pos to);
    char repr();
};

class square {
public:
    piece_p p{nullptr};
    bool is_occupied() {return (p.get() != nullptr);}
};

class game {
    std::vector<piece_p> pieces;
    square board[size][size];
    bool is_valid_move(piece_p piece, pos to);
public:
    game () : board() {}
    void move(piece_p piece, pos to);
    void set_start_position();
    void print();
};

} // namespace chess
