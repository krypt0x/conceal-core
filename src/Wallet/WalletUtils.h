// Copyright (c) 2011-2015 The Cryptonote developers
// Copyright (c) 2015-2016 The Bytecoin developers
// Copyright (c) 2016-2017 The TurtleCoin developers
// Copyright (c) 2017-2018 krypt0x aka krypt0chaos
// Copyright (c) 2018 The Circle Foundation
//
// This file is part of Conceal Sense Crypto Engine.
//
// Conceal is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Conceal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Conceal.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <string>

#include "IWallet.h"
#include "CryptoNoteCore/Currency.h"
#include "Wallet/WalletGreen.h"

namespace CryptoNote {

void throwIfKeysMismatch(const Crypto::SecretKey& secretKey, const Crypto::PublicKey& expectedPublicKey, const std::string& message = "");
bool validateAddress(const std::string& address, const CryptoNote::Currency& currency);

std::ostream& operator<<(std::ostream& os, CryptoNote::WalletTransactionState state);
std::ostream& operator<<(std::ostream& os, CryptoNote::WalletTransferType type);
std::ostream& operator<<(std::ostream& os, CryptoNote::WalletGreen::WalletState state);
std::ostream& operator<<(std::ostream& os, CryptoNote::WalletGreen::WalletTrackingMode mode);

class TransferListFormatter {
public:
  explicit TransferListFormatter(const CryptoNote::Currency& currency, const WalletGreen::TransfersRange& range);

  void print(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream& os, const TransferListFormatter& formatter);

private:
  const CryptoNote::Currency& m_currency;
  const WalletGreen::TransfersRange& m_range;
};

class WalletOrderListFormatter {
public:
  explicit WalletOrderListFormatter(const CryptoNote::Currency& currency, const std::vector<CryptoNote::WalletOrder>& walletOrderList);

  void print(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream& os, const WalletOrderListFormatter& formatter);

private:
  const CryptoNote::Currency& m_currency;
  const std::vector<CryptoNote::WalletOrder>& m_walletOrderList;
};

}