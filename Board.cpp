#include "Board.h"

Board::Board(unsigned int dimensions)
    : dimensions(dimensions), hoverPiece(nullptr), isMousePressed(false)
{
    int windowSize = 1300;

    pieces.reserve(dimensions * dimensions);
    pieceSelected.resize(dimensions * dimensions, false);
    characters.reserve(dimensions * dimensions);

    float pieceSize = static_cast<float>(windowSize) / dimensions;
    for (unsigned int row = 0; row < dimensions; ++row)
    {
        for (unsigned int col = 0; col < dimensions; ++col)
        {
            float x = col * pieceSize + 100 ;
            float y = row * pieceSize + 100 ;
            pieces.emplace_back(x, y, pieceSize, 'A' + (row * dimensions + col));
        }
    }
}

void Board::update(const sf::Vector2f& mousePosition, bool isMousePressed)
{
    // Track whether any piece was clicked or not
    bool pieceClicked = false;
    hoverPiece = nullptr;

    for (size_t i = 0; i < pieces.size(); ++i)
    {
        if (pieces[i].getGlobalBounds().contains(mousePosition))
        {
            hoverPiece = &pieces[i];
            
            if (isMousePressed)
            {
                pieceSelected[i] = true;
                characters.push_back(pieces[i].getCharacter());
            } 
            else 
            {
                for (size_t i = 0; i < pieces.size(); ++i)
                {
                    pieceSelected[i] = false;
                }
            }
            pieceClicked = true; 
            break;
        }
    }

    // If no piece was clicked and the mouse is pressed, unclick all pieces
    if (!pieceClicked && isMousePressed)
    {
        printWord(); // Print the word before clearing the array
        characters.clear();
        for (size_t i = 0; i < pieces.size(); ++i)
        {
            pieceSelected[i] = false;
        }
    }
}


void Board::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - board.getPosition();
        update(mousePosition, isMousePressed);
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

        if (pieceSelected[i])
        {
            sf::FloatRect bounds = piece.getGlobalBounds();
            highlight.setSize(sf::Vector2f(bounds.width, bounds.height));
            highlight.setPosition(bounds.left, bounds.top);
            highlight.setOutlineThickness(2.0f);

            // First draw with transparent fill color and green outline
            highlight.setFillColor(sf::Color::Transparent);
            highlight.setOutlineColor(sf::Color::Green);
            sf::Text pieceText = pieces[i].getCharacterText() ;
            target.draw(highlight);
            target.draw(pieceText);

            // Draw the piece, including its text
            piece.render(target);

            // Draw again with green fill color and black outline
            highlight.setFillColor(sf::Color::Green);   
            highlight.setOutlineColor(sf::Color::Black);
            target.draw(highlight);
            target.draw(pieceText);
        }
        else
        {
            piece.render(target);
        }
    }
}

void Board::printWord()
{
    if (!characters.empty())
    {
        std::string word(characters.begin(), characters.end());
        std::cout << "Word: " << word << std::endl;
    }
    else
    {
        std::cout << "No characters in the array." << std::endl;
    }

    characters.clear();
}

void Board::initializeRandomLetters()
{
    for (auto& piece : pieces)
    {
        piece.setRandomLetter();
    }
}