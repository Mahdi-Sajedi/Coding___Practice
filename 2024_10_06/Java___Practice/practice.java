Set<Integer> nums = new HashSet<Integer>();

for (int i=1; i<=10; i++) {
  nums.add(i);
}

Iterator<Integer> it = nums.iterator();
while (it.hasNext()) {
  int val = it.next(); // some random order
}

nums.contains(9); //true
nums.containsAll(Arrays.asList(1, 2, 3)); //true
nums.addAll(Arrays.asList(16, 17)); // union -- nums changes

HashMap<String, String> map = new HashMap<>();
map.put("name", "Lex");

String value = map.get("age"); // value == null
// python
//assert map.get("age") == None
if (map.containsKey("age")){
  //
}
map.size(); // returns integer

Map<String, String> states = new HashMap<String, String>();

states.put("ca", "California");
System.out.println(states.get("ca"));
System.out.println(states.get("zz")); // null -- not error
Collection<String> values = states.values();
System.out.println(values); // [California]

Set<String> keys = states.keySet();
for (Stirng key: keys) {
  System.out.println(key + "->" + states.get(key)); // some random order
}

// complex use case
Map<String, List<Integer>> map = new HashMap<String, List<Integer>>();
List<Integer> nums = new ArrayList<Integer>();
nums.addAll(Arrays.asList(1, 2, 3));
map.put("1-3", nums);

//
Set<Map.Entry<String, String>> entries = states.entrySet();
for (Map.Entry<String, String> entry: entries) {
  System.out.println(entry.getKey() + "->" + entry.getValue());
}
