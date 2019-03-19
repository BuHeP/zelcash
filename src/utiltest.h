// Copyright (c) 2018 The Zelcash developers
// Copyright (c) 2016 The Zcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZELCASH_UTIL_TEST_H
#define ZELCASH_UTIL_TEST_H

#include "key_io.h"
#include "wallet/wallet.h"
#include "zelcash/JoinSplit.hpp"
#include "zelcash/Note.hpp"
#include "zelcash/NoteEncryption.hpp"
#include "zelcash/zip32.h"

// Sprout
CWalletTx GetValidSproutReceive(ZCJoinSplit& params,
                                const libzelcash::SproutSpendingKey& sk,
                                CAmount value,
                                bool randomInputs,
                                int32_t version = 2);
CWalletTx GetInvalidCommitmentSproutReceive(ZCJoinSplit& params,
                                const libzelcash::SproutSpendingKey& sk,
                                CAmount value,
                                bool randomInputs,
                                int32_t version = 2);
libelcash::SproutNote GetSproutNote(ZCJoinSplit& params,
                                   const libzelcash::SproutSpendingKey& sk,
                                   const CTransaction& tx, size_t js, size_t n);
CWalletTx GetValidSproutSpend(ZCJoinSplit& params,
                              const libzelcash::SproutSpendingKey& sk,
                              const libzelcash::SproutNote& note,
                              CAmount value);

// Sapling
static const std::string T_SECRET_REGTEST = "cND2ZvtabDbJ1gucx9GWH6XT9kgTAqfb6cotPt5Q5CyxVDhid2EN";

struct TestSaplingNote {
    libzelcash::SaplingNote note;
    SaplingMerkleTree tree;
};

const Consensus::Params& RegtestActivateAcadia();

void RegtestDeactivateAcadia();

libzelcash::SaplingExtendedSpendingKey GetTestMasterSaplingSpendingKey();

CKey AddTestCKeyToKeyStore(CBasicKeyStore& keyStore);

/**
 * Generate a dummy SaplingNote and a SaplingMerkleTree with that note's commitment.
 */
TestSaplingNote GetTestSaplingNote(const libzelcash::SaplingPaymentAddress& pa, CAmount value);

CWalletTx GetValidSaplingReceive(const Consensus::Params& consensusParams,
                                 CBasicKeyStore& keyStore,
                                 const libzelcash::SaplingExtendedSpendingKey &sk,
                                 CAmount value);

#endif // ZELCASH_UTIL_TEST_H