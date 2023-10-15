
#ifndef PKMNPATTERNREDESIGN_PROTOCD_H
#define PKMNPATTERNREDESIGN_PROTOCD_H
#include <iostream>


// open fstream
// cards.emplace_back()  // default constructor
// read in cardData
// cards.back().cdProto.MergeFromCodedStream(&input)
//
// assembleCardID(PlayerID pId,

namespace CardData
{
    const int MATCH_ANY_INT_VAL = 0;
    const std::string MATCH_ANY_STR_VAL = "";

    template <typename T>
    bool matches(const T& lhs, const T& rhs);

    struct CardDataProtoProxy
    {
        enum CardType
        {
            CT_ANY = 0,
            CT_PKMN = 1,
            CT_ENERGY = 2,
            CT_TRAINER = 3
        };

        enum EnergyType
        {
            ET_ANY = 0,
            ET_FIRE = 1,
            ET_WATER = 2,
            ET_GRASS = 3,
            ET_ELECTRIC = 4,
            ET_FIGHTING = 5,
            ET_PSYCHIC = 6,
            ET_COLORLESS = 7
        };

        int32_t cId;
        std::string cName;
        CardType cType;
        EnergyType eType;

        inline const int32_t cid() const { return cId; }
        inline void set_cid(int32_t value) { cId = value; }

        inline const std::string& cname() const { return cName; }
        inline void set_cname(const std::string& value) { cName = value; }

        inline const CardType ctype() const { return cType; }
        inline void set_ctype(CardType value) { cType = value; }

        inline const EnergyType etype() const { return eType; }
        inline void set_etype(EnergyType value) { eType = value; }
    };

    class CardDataWrapper
    {
    public:
        inline CardDataWrapper(const CardDataProtoProxy& cdpp) : cdProto(cdpp) {};


    private:
        CardDataProtoProxy cdProto;

    };

//    bool writeDelimitedTo(const google::protobuf::MessageLite& message,
//                          google::protobuf::io::ZeroCopyOutputStream* rawOutput)
//    {
//        // We create a new coded stream for each message.  Don't worry, this is fast.
//        google::protobuf::io::CodedOutputStream output(rawOutput);
//
//        // Write the size.
//        const int size = message.ByteSize();
//        output.WriteVarint32(size);
//
//        uint8_t* buffer = output.GetDirectBufferForNBytesAndAdvance(size);
//        if (buffer != NULL)
//        {
//            // Optimization:  The message fits in one buffer, so use the faster
//            // direct-to-array serialization path.
//            message.SerializeWithCachedSizesToArray(buffer);
//        }
//
//        else
//        {
//            // Slightly-slower path when the message is multiple buffers.
//            message.SerializeWithCachedSizes(&output);
//            if (output.HadError())
//                return false;
//        }
//
//        return true;
//    }
//
//    bool readDelimitedFrom(google::protobuf::io::ZeroCopyInputStream* rawInput, google::protobuf::MessageLite* message, bool* clean_eof)
//    {
//        // We create a new coded stream for each message.  Don't worry, this is fast,
//        // and it makes sure the 64MB total size limit is imposed per-message rather
//        // than on the whole stream.  (See the CodedInputStream interface for more
//        // info on this limit.)
//        google::protobuf::io::CodedInputStream input(rawInput);
//        const int start = input.CurrentPosition();
//        if (clean_eof)
//            *clean_eof = false;
//
//
//        // Read the size.
//        uint32_t size;
//        if (!input.ReadVarint32(&size))
//        {
//            if (clean_eof)
//                *clean_eof = input.CurrentPosition() == start;
//            return false;
//        }
//        // Tell the stream not to read beyond that size.
//        google::protobuf::io::CodedInputStream::Limit limit = input.PushLimit(size);
//
//        // Parse the message.
//        if (!message->MergeFromCodedStream(&input)) return false;
//        if (!input.ConsumedEntireMessage()) return false;
//
//        // Release the limit.
//        input.PopLimit(limit);
//
//        return true;
//    }
//
//    template <typename T>
//    bool writeManyToFile(std::deque<T> messages, std::string filename) {
//        int outfd = open(filename.c_str(), O_WRONLY | O_CREAT | O_TRUNC);
//        google::protobuf::io::FileOutputStream fout(outfd);
//
//        bool success;
//        for (auto msg: messages) {
//            success = google::protobuf::util::SerializeDelimitedToZeroCopyStream(
//                    msg, &fout);
//            if (! success) {
//                std::cout << "Writing Failed" << std::endl;
//                break;
//            }
//        }
//        fout.Close();
//        close(outfd);
//        return success;
//    }
//
//    template <typename T>
//    std::deque<T> readManyFromFile(std::string filename) {
//        int infd = open(filename.c_str(), O_RDONLY);
//
//        google::protobuf::io::FileInputStream fin(infd);
//        bool keep = true;
//        bool clean_eof = true;
//        std::deque<T> out;
//
//        while (keep) {
//            T msg;
//            keep = google::protobuf::util::ParseDelimitedFromZeroCopyStream(
//                    &msg, &fin, nullptr);
//            if (keep)
//                out.push_back(msg);
//        }
//        fin.Close();
//        close(infd);
//        return out;
//    }



};

// may need to cast lhs/rhs
// need to veritfy legal cast before we do it in this function
template <typename T>
bool CardData::matches(const T& lhs, const T& rhs)
{
    return lhs == MATCH_ANY_INT_VAL || rhs == MATCH_ANY_INT_VAL || lhs == rhs;
};

template <>
bool CardData::matches(const std::string& lhs, const std::string& rhs)
{
    return lhs == MATCH_ANY_STR_VAL || rhs == MATCH_ANY_STR_VAL || lhs == rhs;
};



#endif //PKMNPATTERNREDESIGN_PROTOCD_H
