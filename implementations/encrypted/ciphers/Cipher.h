#pragma once
#ifndef MESSMER_BLOCKSTORE_IMPLEMENTATIONS_ENCRYPTED_CIPHERS_CIPHER_H_
#define MESSMER_BLOCKSTORE_IMPLEMENTATIONS_ENCRYPTED_CIPHERS_CIPHER_H_

#include <boost/concept_check.hpp>
#include <cstdint>

namespace blockstore {
namespace encrypted {

template<class X>
struct CipherConcept {
public:
  BOOST_CONCEPT_USAGE(CipherConcept) {
    same_type(UINT32_C(0), X::ciphertextSize(UINT32_C(5)));
    same_type(UINT32_C(0), X::plaintextSize(UINT32_C(5)));
    typename X::EncryptionKey key = X::EncryptionKey::CreateRandom();
    same_type(cpputils::Data(0), X::encrypt((byte*)nullptr, UINT32_C(0), key));
    same_type(boost::optional<cpputils::Data>(cpputils::Data(0)), X::decrypt((byte*)nullptr, UINT32_C(0), key));
  }

private:
  // Type deduction will fail unless the arguments have the same type.
  template <typename T> void same_type(T const&, T const&);
};

}
}



#endif
