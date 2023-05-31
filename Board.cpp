#include "Board.h"

Board::Board(unsigned int dimensions)
    : dimensions(dimensions), hoverPiece(nullptr), isMousePressed(false)
{
    int windowSize = 1500;

    board.setSize(sf::Vector2f(windowSize, windowSize));
    board.setFillColor(sf::Color(200, 200, 200));

    pieces.reserve(dimensions * dimensions);
    pieceSelected.resize(dimensions * dimensions, false);
    float pieceSize = static_cast<float>(windowSize) / dimensions;
    for (unsigned int row = 0; row < dimensions; ++row)
    {
        for (unsigned int col = 0; col < dimensions; ++col)
        {
            float x = col * pieceSize;
            float y = row * pieceSize;
            pieces.emplace_back(x, y, pieceSize, 'A' + (row * dimensions + col));
        }
    }
}

void Board::update(const sf::Vector2f& mousePosition)
{
    hoverPiece = nullptr;

    // Track whether any piece was clicked or not
    bool pieceClicked = false;

    for (size_t i = 0; i < pieces.size(); ++i)
    {
        if (pieces[i].getGlobalBounds().contains(mousePosition))
        {
            hoverPiece = &pieces[i];

            if (isMousePressed)
            {
                // Toggle the selection state of the clicked piece
                pieceSelected[i] = !pieceSelected[i];
                pieceClicked = true;
            }
            break;
        }
    }

    // If a piece was clicked, update the selection state of all pieces under the mouse
    if (pieceClicked)
    {
        bool highlight = pieceSelected[hoverPiece - &pieces[0]];

        for (size_t i = 0; i < pieces.size(); ++i)
        {
            if (pieces[i].getGlobalBounds().contains(mousePosition))
            {
                pieceSelected[i] = highlight;
            }
        }
    }
}

void Board::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - board.getPosition();
        update(mousePosition);
    }
    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        isMousePressed = true;
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        isMousePressed = false;
    }
}

void Board::render(sf::RenderTarget& target) const
{
    target.draw(board);
    sf::RectangleShape highlight;
    for (size_t i = 0; i < pieces.size(); ++i)
    {
        const auto& piece = pieces[i];
        piece.render(target);
        if (&piece == hoverPiece || pieceSelected[i])
        {
            sf::FloatRect bounds = piece.getGlobalBounds();
            highlight.setSize(sf::Vector2f(bounds.width, bounds.height));
            highlight.setPosition(bounds.left, bounds.top);
            highlight.setFillColor(sf::Color::Green);
            target.draw(highlight);
        }
    }
}

void Board::initializeRandomLetters()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('A', 'Z');

    for (auto& piece : pieces)
    {
        char randomLetter = static_cast<char>(dis(gen));
        piece.setLetter(randomLetter);
    }
}