// SPDX-License-Identifier: BSD-3-Clause
#ifndef PARSER_TOKENISER_HXX
#define PARSER_TOKENISER_HXX

#include <utility>
#include <substrate/fd>
#include "recogniser.hxx"
#include "types.hxx"

namespace mangrove::parser
{
	inline namespace internal
	{
		using substrate::fd_t;
	} // namespace internal

	struct Tokeniser final
	{
	private:
		fd_t _file;
		Char currentChar{};
		types::Position position{};
		types::Token _token{};

		Char nextChar() noexcept;
		void readToken() noexcept;

	public:
		Tokeniser(fd_t &&file) : _file{std::move(file)} { }

		[[nodiscard]] auto token() const noexcept { return _token; }

		types::Token &next() noexcept;
	};
} // namespace mangrove::parser

#endif /*PARSER_TOKENISER_HXX*/
