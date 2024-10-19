#define PAYLOAD_NAMESPACE "RSM" // Change to your namespace (This will depend on what your namespace in your C# code is)
#define PAYLOAD_CLASS "Loader" // Leave same
#define PAYLOAD_MAIN "Init" // Leave same
#define MONO_DLL L"mono-2.0-bdwgc.dll" // Leave same

// typedefs and fields for required mono functions
typedef void(__cdecl* t_mono_thread_attach)(MonoDomain*);
t_mono_thread_attach fnThreadAttach;
typedef  MonoDomain* (__cdecl* t_mono_get_root_domain)(void);
t_mono_get_root_domain fnGetRootDomain;
typedef MonoAssembly* (__cdecl* t_mono_assembly_open)(const char*, MonoImageOpenStatus*);
t_mono_assembly_open fnAssemblyOpen;
typedef MonoImage* (__cdecl* t_mono_assembly_get_image)(MonoAssembly*);
t_mono_assembly_get_image fnAssemblyGetImage;
typedef MonoClass* (__cdecl* t_mono_class_from_name)(MonoImage*, const char*, const char*);
t_mono_class_from_name fnClassFromName;
typedef MonoMethod* (__cdecl* t_mono_class_get_method_from_name)(MonoClass*, const char*, int);
t_mono_class_get_method_from_name fnMethodFromName;
typedef MonoObject* (__cdecl* t_mono_runtime_invoke)(MonoMethod*, void*, void**, MonoObject**);
t_mono_runtime_invoke fnRuntimeInvoke;
typedef const char* (__cdecl* t_mono_assembly_getrootdir)(void);
t_mono_assembly_getrootdir fnGetRootDir;
typedef MonoObject* (__cdecl* t_mono_object_new)(MonoDomain*, MonoClass*);

typedef void (*t_mono_assembly_close)(MonoAssembly*);
typedef MonoClass* (__cdecl* t_mono_object_get_class)(MonoObject*);
typedef const char* (__cdecl* t_mono_class_get_name)(MonoClass*);
typedef const char* (__cdecl* t_mono_class_get_namespace)(MonoClass*);
typedef char* (__cdecl* t_mono_string_to_utf8)(MonoString*);
typedef void(__cdecl* t_mono_free)(void*);
typedef void(__cdecl* t_mono_string_free)(char*);
typedef void(__cdecl* t_mono_runtime_object_init)(MonoObject*);
typedef void(__cdecl* t_mono_thread_detach)(MonoDomain*);
typedef void(__cdecl* t_mono_gc_collect)(int);
typedef int(__cdecl* t_mono_gc_max_generation)(void);
typedef void(__cdecl* t_mono_domain_unload)(MonoDomain*); 
typedef MonoImage* (__cdecl* t_mono_image_open_from_data)(char*, uint32_t, mono_bool, MonoImageOpenStatus*);
typedef MonoAssembly* (__cdecl* t_mono_assembly_load_from)(MonoImage*, const char*, MonoImageOpenStatus*);
typedef const char* (__cdecl* t_mono_image_get_name)(MonoImage*);
typedef MonoDomain* (__cdecl* t_mono_domain_get_normal)(void);
typedef void(__cdecl* t_mono_image_init)(MonoImage*);
typedef MonoDomain*(__cdecl* t_mono_domain_create_appdomain)(char*, char*);
typedef void(__cdecl* t_mono_domain_set)(MonoDomain*, mono_bool);

t_mono_assembly_close fnMonoAssemblyClose;
t_mono_object_get_class fnObjectGetClass;
t_mono_class_get_name fnClassGetName;
t_mono_class_get_namespace fnClassGetNamespace;
t_mono_string_to_utf8 fnStringToUtf8;
t_mono_free fnMonoFree;
t_mono_string_free fnStringFree;
t_mono_object_new fnMonoObjectNew;
t_mono_runtime_object_init fnMonoRuntimeObjectInit;
t_mono_thread_detach fnMonoThreadDetach;
t_mono_gc_collect fnMonoGcCollect;
t_mono_gc_max_generation fnMonoGcMaxGen;
t_mono_domain_unload fnMonoDomainUnload;
t_mono_image_open_from_data fnMonoImageOpenFromData;
t_mono_assembly_load_from fnMonoAssemblyLoadFrom;
t_mono_image_get_name fnMonoImageGetName;
t_mono_domain_get_normal fnMonoDomainGetNormal;
t_mono_image_init fnMonoImageInit;
t_mono_domain_create_appdomain fnMonoCreateAppdomain;
t_mono_domain_set fnMonoDomainSet;

MonoAssembly* assembly;
MonoDomain* domain1;

void initMonoFunctions(HMODULE mono) {
	fnMonoAssemblyClose = (t_mono_assembly_close)GetProcAddress(mono, "mono_assembly_close");
	fnThreadAttach = (t_mono_thread_attach)GetProcAddress(mono, "mono_thread_attach");
	fnGetRootDomain = (t_mono_get_root_domain)GetProcAddress(mono, "mono_get_root_domain");
	fnAssemblyOpen = (t_mono_assembly_open)GetProcAddress(mono, "mono_assembly_open");
	fnAssemblyGetImage = (t_mono_assembly_get_image)GetProcAddress(mono, "mono_assembly_get_image");
	fnClassFromName = (t_mono_class_from_name)GetProcAddress(mono, "mono_class_from_name");
	fnMethodFromName = (t_mono_class_get_method_from_name)GetProcAddress(mono, "mono_class_get_method_from_name");
	fnRuntimeInvoke = (t_mono_runtime_invoke)GetProcAddress(mono, "mono_runtime_invoke");
	fnGetRootDir = (t_mono_assembly_getrootdir)GetProcAddress(mono, "mono_assembly_getrootdir");
	fnObjectGetClass = (t_mono_object_get_class)GetProcAddress(mono, "mono_object_get_class");
	fnClassGetName = (t_mono_class_get_name)GetProcAddress(mono, "mono_class_get_name");
	fnClassGetNamespace = (t_mono_class_get_namespace)GetProcAddress(mono, "mono_class_get_namespace");
	fnStringToUtf8 = (t_mono_string_to_utf8)GetProcAddress(mono, "mono_string_to_utf8");
	fnMonoFree = (t_mono_free)GetProcAddress(mono, "mono_free");
	fnStringFree = (t_mono_string_free)GetProcAddress(mono, "mono_string_free");
	fnMonoObjectNew = (t_mono_object_new)GetProcAddress(mono, "mono_object_new");
	fnMonoRuntimeObjectInit = (t_mono_runtime_object_init)GetProcAddress(mono, "mono_runtime_object_init");
	fnMonoThreadDetach = (t_mono_thread_detach)GetProcAddress(mono, "mono_thread_detach");
	fnMonoGcCollect = (t_mono_gc_collect)GetProcAddress(mono, "mono_gc_collect");
	fnMonoGcMaxGen = (t_mono_gc_max_generation)GetProcAddress(mono, "mono_gc_max_generation");
	fnMonoDomainUnload = (t_mono_domain_unload)GetProcAddress(mono, "mono_domain_unload");
	fnMonoImageOpenFromData = (t_mono_image_open_from_data)GetProcAddress(mono, "mono_image_open_from_data");
	fnMonoAssemblyLoadFrom = (t_mono_assembly_load_from)GetProcAddress(mono, "mono_assembly_load_from");
	fnMonoImageGetName = (t_mono_image_get_name)GetProcAddress(mono, "mono_image_get_name");
	fnMonoImageInit = (t_mono_image_init)GetProcAddress(mono, "mono_image_init");
	fnMonoDomainGetNormal = (t_mono_domain_get_normal)GetProcAddress(mono, "mono_domain_get_normal");
	fnMonoCreateAppdomain = (t_mono_domain_create_appdomain)GetProcAddress(mono, "mono_domain_create_appdomain");
	fnMonoDomainSet = (t_mono_domain_set)GetProcAddress(mono, "mono_domain_set");
}


void InjectMonoAssembly() {
	std::string assemblyDir;

	HMODULE mono;
	MonoImage* image;
	MonoMethod* method;
	MonoDomain* domain; // Глобальная переменная для хранения домена
	MonoClass* klass;


	/* grab the mono dll module */
	mono = LoadLibraryW(MONO_DLL);
	/* initialize mono functions */
	initMonoFunctions(mono);
	/* grab the root domain */
	domain = fnGetRootDomain();
	fnThreadAttach(domain);
	/* Grab our root directory*/
	assemblyDir.append(fnGetRootDir());
	assemblyDir.append(ASSEMBLY_PATH);
	/* open payload assembly */
	domain1 = fnMonoCreateAppdomain((char*)assemblyDir.c_str(), nullptr);
	fnMonoDomainSet(domain1, 0);
	
	std::ifstream file(assemblyDir.c_str(), std::ios::binary);
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), {});

	MonoImageOpenStatus status;
	image = fnMonoImageOpenFromData((char*)buffer.data(), (uint32_t)buffer.size(), 1, &status);
	fnMonoImageInit(image);
	assembly = fnMonoAssemblyLoadFrom(image, "", &status);
	if (image == NULL) return;
	/* grab the class */
	klass = fnClassFromName(image, PAYLOAD_NAMESPACE, PAYLOAD_CLASS);
	if (klass == NULL) return;
	MonoObject* result = fnMonoObjectNew(domain1, klass);
	fnMonoRuntimeObjectInit(result);
	/* grab the hack entrypoint */
	method = fnMethodFromName(klass, PAYLOAD_MAIN, 0);
	if (method == NULL) return;
	/* call our entrypoint */
	fnRuntimeInvoke(method, result, NULL, NULL);
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		InjectMonoAssembly();
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}