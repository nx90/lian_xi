// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protobufs.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protobufs_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protobufs_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_protobufs_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protobufs_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace protobufs {
class remoteAdd;
struct remoteAddDefaultTypeInternal;
extern remoteAddDefaultTypeInternal _remoteAdd_default_instance_;
class remoteReturn;
struct remoteReturnDefaultTypeInternal;
extern remoteReturnDefaultTypeInternal _remoteReturn_default_instance_;
}  // namespace protobufs
PROTOBUF_NAMESPACE_OPEN
template<> ::protobufs::remoteAdd* Arena::CreateMaybeMessage<::protobufs::remoteAdd>(Arena*);
template<> ::protobufs::remoteReturn* Arena::CreateMaybeMessage<::protobufs::remoteReturn>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protobufs {

// ===================================================================

class remoteAdd final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:protobufs.remoteAdd) */ {
 public:
  inline remoteAdd() : remoteAdd(nullptr) {}
  ~remoteAdd() override;
  explicit constexpr remoteAdd(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  remoteAdd(const remoteAdd& from);
  remoteAdd(remoteAdd&& from) noexcept
    : remoteAdd() {
    *this = ::std::move(from);
  }

  inline remoteAdd& operator=(const remoteAdd& from) {
    CopyFrom(from);
    return *this;
  }
  inline remoteAdd& operator=(remoteAdd&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const remoteAdd& default_instance() {
    return *internal_default_instance();
  }
  static inline const remoteAdd* internal_default_instance() {
    return reinterpret_cast<const remoteAdd*>(
               &_remoteAdd_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(remoteAdd& a, remoteAdd& b) {
    a.Swap(&b);
  }
  inline void Swap(remoteAdd* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(remoteAdd* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline remoteAdd* New() const final {
    return new remoteAdd();
  }

  remoteAdd* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<remoteAdd>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const remoteAdd& from);
  void MergeFrom(const remoteAdd& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(remoteAdd* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protobufs.remoteAdd";
  }
  protected:
  explicit remoteAdd(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPara1FieldNumber = 1,
    kPara2FieldNumber = 2,
  };
  // int64 para1 = 1;
  void clear_para1();
  ::PROTOBUF_NAMESPACE_ID::int64 para1() const;
  void set_para1(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_para1() const;
  void _internal_set_para1(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // int64 para2 = 2;
  void clear_para2();
  ::PROTOBUF_NAMESPACE_ID::int64 para2() const;
  void set_para2(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_para2() const;
  void _internal_set_para2(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:protobufs.remoteAdd)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int64 para1_;
  ::PROTOBUF_NAMESPACE_ID::int64 para2_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_protobufs_2eproto;
};
// -------------------------------------------------------------------

class remoteReturn final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:protobufs.remoteReturn) */ {
 public:
  inline remoteReturn() : remoteReturn(nullptr) {}
  ~remoteReturn() override;
  explicit constexpr remoteReturn(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  remoteReturn(const remoteReturn& from);
  remoteReturn(remoteReturn&& from) noexcept
    : remoteReturn() {
    *this = ::std::move(from);
  }

  inline remoteReturn& operator=(const remoteReturn& from) {
    CopyFrom(from);
    return *this;
  }
  inline remoteReturn& operator=(remoteReturn&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const remoteReturn& default_instance() {
    return *internal_default_instance();
  }
  static inline const remoteReturn* internal_default_instance() {
    return reinterpret_cast<const remoteReturn*>(
               &_remoteReturn_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(remoteReturn& a, remoteReturn& b) {
    a.Swap(&b);
  }
  inline void Swap(remoteReturn* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(remoteReturn* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline remoteReturn* New() const final {
    return new remoteReturn();
  }

  remoteReturn* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<remoteReturn>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const remoteReturn& from);
  void MergeFrom(const remoteReturn& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(remoteReturn* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protobufs.remoteReturn";
  }
  protected:
  explicit remoteReturn(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAnsFieldNumber = 1,
  };
  // int64 ans = 1;
  void clear_ans();
  ::PROTOBUF_NAMESPACE_ID::int64 ans() const;
  void set_ans(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_ans() const;
  void _internal_set_ans(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:protobufs.remoteReturn)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int64 ans_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_protobufs_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// remoteAdd

// int64 para1 = 1;
inline void remoteAdd::clear_para1() {
  para1_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 remoteAdd::_internal_para1() const {
  return para1_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 remoteAdd::para1() const {
  // @@protoc_insertion_point(field_get:protobufs.remoteAdd.para1)
  return _internal_para1();
}
inline void remoteAdd::_internal_set_para1(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  para1_ = value;
}
inline void remoteAdd::set_para1(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_para1(value);
  // @@protoc_insertion_point(field_set:protobufs.remoteAdd.para1)
}

// int64 para2 = 2;
inline void remoteAdd::clear_para2() {
  para2_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 remoteAdd::_internal_para2() const {
  return para2_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 remoteAdd::para2() const {
  // @@protoc_insertion_point(field_get:protobufs.remoteAdd.para2)
  return _internal_para2();
}
inline void remoteAdd::_internal_set_para2(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  para2_ = value;
}
inline void remoteAdd::set_para2(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_para2(value);
  // @@protoc_insertion_point(field_set:protobufs.remoteAdd.para2)
}

// -------------------------------------------------------------------

// remoteReturn

// int64 ans = 1;
inline void remoteReturn::clear_ans() {
  ans_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 remoteReturn::_internal_ans() const {
  return ans_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 remoteReturn::ans() const {
  // @@protoc_insertion_point(field_get:protobufs.remoteReturn.ans)
  return _internal_ans();
}
inline void remoteReturn::_internal_set_ans(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  ans_ = value;
}
inline void remoteReturn::set_ans(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_ans(value);
  // @@protoc_insertion_point(field_set:protobufs.remoteReturn.ans)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobufs

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protobufs_2eproto
