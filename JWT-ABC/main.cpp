#include "jwt-cpp/jwt.h"
#include <iostream>

int main()
{
    std::cout << "Generate a Token" << std::endl;
    // generate a token
    std::string token = jwt::create()
                          .set_type("JWT")                                                                  // typ
                          .set_issuer("server")                                                             // iss
                          .set_subject("topic")                                                             // sub
                          .set_audience("client")                                                           // aud
                          .set_issued_at(std::chrono::system_clock::now())                                  // iat
                          .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{ 3600 })  // exp
                          .set_payload_claim("sample", jwt::claim(std::string("abc")))  // customized
                          .sign(jwt::algorithm::hs256{ "123456" });                     // alg

    std::cout << "token: " << token << std::endl;

    // Decode a token
    auto decoded = jwt::decode(token);

    // Create a verifier
    auto verifier = jwt::verify()
                      .allow_algorithm(jwt::algorithm::hs256{ "123456" })  //  password
                      .with_issuer("server")                               // issuer
                      .with_subject("topic");                              // topic
    try {
        verifier.verify(decoded);
        std::cout << "verify successfully!" << std::endl;
    } catch (jwt::token_verification_exception e) {
        std::cout << "verify error: " << e.what() << std::endl;
    }

    // Get all payload
    for (auto &e : decoded.get_payload_claims()) {
        std::cout << e.first << " = " << e.second.to_json() << std::endl;
    }

    // need to catch exception
    try {
        std::string sample = decoded.get_payload_claim("sample").as_string();
        std::cout << "sample = " << sample << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}