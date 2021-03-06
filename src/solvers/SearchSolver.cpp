#include "SearchSolver.hpp"
#include "GraphInputParser.hpp"
#include "StatusException.hpp"
#include "ParserExceptions.hpp"

namespace solver
{

    SearchSolver::SearchSolver(std::unique_ptr<searcher::Searcher<searcher::SearchResult, std::pair<uint32_t, uint32_t>>> searcher)
        : m_searcher(std::move(searcher)) {}

    std::string SearchSolver::solve(const std::string &problemString) const
    {
        parser::GraphInputParser parser;

        try
        {
            searcher::Graph problem = parser.parseInput(problemString);
            return (m_searcher->search(problem)).toString();
        }
        catch (const searcher::exceptions::PathDoesNotExistException &e)
        {
            throw status_exception::StatusException(e.what(), 1);
        }
        catch (const searcher::exceptions::InvalidPositionException &e)
        {
            throw status_exception::StatusException(e.what(), 2);
        }
        catch (const parser::exceptions::InvalidInputException &e)
        {
            throw status_exception::StatusException(e.what(), 4);
        }
    }
}